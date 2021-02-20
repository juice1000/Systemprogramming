#include "bruteforcer.h"
#include <unistd.h>

	// THIS SCRIPT WAS DEVELOPED BY JULIEN LOOK

int main(int argc, char *argv[]) {
	// Argumente checken
	if (argc != 4) {
		fprintf(stderr, "usage: %s pwdmaxlen workers hashfile\n", argv[0]);
		exit(1);
	}
	
	char *filename = NULL;
	hashes *loaded_hashes = NULL;
	

	// Kommandozeilenargumente auslesen und globale und lokale Variablen füllen
	pwd_maxlen = (int) strtol(argv[1], (char **)NULL, 10);
	max_workers = (int) strtol(argv[2], (char **)NULL, 10);
	filename = argv[3];

	// speicher freigeben für worker array und einträge mit 0 initialisieren
	worker = malloc(sizeof(pid_t) * max_workers);
	for (int i = 0; i < max_workers; i++){
		worker[i] = 0;
	}

	
	INFO("\nBRUTEFORCER GESTARTET\n");
	INFO("---------------------\n");
	INFO("Maximale Passwortlänge: %d\n", pwd_maxlen);
	INFO("Anzahl der Worker: %d\n", max_workers);
	INFO("Hashes lesen aus Datei: %s\n", filename);
	INFO("---------------------\n\n");
	
	// Hashes in ein hashes struct laden
	loaded_hashes = load_hashes(filename);

	// Main loop -> Iteriert über alle Hashes
	for (int i = 0; i < loaded_hashes->len; i++) {
		char *hash = loaded_hashes->array[i];
		INFO("\n LOAD HASH NUMBER: %d\n", i); // keep track of iteration through hashes
		
    	// if maximum number of workers running, wait for one process to change status
		while(update_worker() >= max_workers){
			waitpid( -1 , NULL , 0);
		}

		pid_t pid = fork(); 
		
		// Child process
        if(pid == 0){ 
            INFO("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 
			if (crack_hash(hash) != NULL){
				pwd * result = crack_hash(hash);
				printf("\nPASSWORD: ");
				for (int i = 0; i < pwd_maxlen; i++){
        			printf("%c", result->buf[i]);
    			}
				printf("\n");
				free_password(result);
				
			}
            exit(0); 
        }
		// parent process (<0 not considered as error handling not necessary in this task)
		else if (pid > 0){
			int j = 0;
			while(j <= max_workers){
				if(worker[j] == 0){ //check for empty entry in array and assign newly generated pid
					worker[j]=pid;
					
					break;
				}
				j++;
				
			}
		} 
		INFO("\nWORKERS ACTIVE: %d\n",update_worker());
		
	}

	
	while(update_worker() > 0){
		wait(NULL);	// Parent process still needs to wait until all child processes are finished before it can terminate
	}
	free_hashes(loaded_hashes);
	free(worker);
	return 0;
}


// Versucht den Hash zu cracken, indem systematisch Passwörter generiert werden
// und darauf getestet wird, ob deren Hash mit hash übereinstimmt
// Returns pwd or NULL if no password was found
pwd *crack_hash(char *hash) {
	// Create new password
	pwd *password = new_password(pwd_maxlen);

	// Generate tempstring so password won't get affected by hashing, compare tempstring with the extracted hash
	char *tempstring = password->buf;
	tempstring = sha256(tempstring);
	test_string(tempstring, hash);
	
	int dead_end = next_password(password); // Create dead_end from return of next_password as while loop breaker
	while (dead_end != 0){

		tempstring = password->buf;
		tempstring = sha256(tempstring);
		if (test_string(tempstring, hash) == 0){
			return password;
		}
        dead_end = next_password(password);

    }
	free_password(password);
		
	return NULL;
	
}

// Berechnet den Hash von string und gibt 1 zurück, wenn er mit hash übereinstimmt, sonst 0
int test_string(char *string, char *hash) {

	if(strncmp(string, hash, 64)==0){
		return 0;
	}
	else{
		return 1;
	}
}

/**
 * Diese Funktion soll alle worker Kindprozesse die in dem Array "worker"
 * gespeichert sind darauf überprüfen, ob diese noch laufen oder bereits
 * beendet sind. Wenn ein Prozess beendet wurde soll der Eintrag in dem Array
 * gelöscht werden (auf 0 setzen), so dass dieser wieder zur Verfügung steht.
 *
 * return value:
 *   Diese Funktion soll die Anzahl der momentan im Hintergrund laufenden
 *   Prozesse zurückgeben. Prozesse die beendet wurden zählen nicht dazu.
 */
int update_worker() {

	int worker_count = 0;
	
	for (int i = 0; i < max_workers; i++) {
		if(worker[i] != 0){	//check if entry is empty
			worker_count = worker_count + 1;
			if (waitpid(worker[i], NULL , WNOHANG) != 0){ //check if process is terminated
				worker[i] = 0;	//set this field as 0
				worker_count = worker_count -1;
			}
		}	
	}
	return worker_count;
}

