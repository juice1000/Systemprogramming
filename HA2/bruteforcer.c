#include "bruteforcer.h"
#include <unistd.h>

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


	worker = malloc(sizeof(pid_t) * max_workers);
	// worker array mit 0 initialisieren
	for (int i = 0; i < max_workers; i++){
		worker[i] = 0;
	}

	pid_t p = fork();
	pid_t r = fork();

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
		printf("\n%d LOAD HASH NUMBER: ", i);
		
		if (p == 0){
			printf("\n%d CHILD: ", p);
			// Hash mit crack_hash versuchen zu knacken
			if (crack_hash(hash) != NULL){
				pwd * result = crack_hash(hash);
				printf("\nPASSWORD: ");
				for (int i = 0; i < pwd_maxlen; i++){
					// TODO print password if found, test with crack_hash == NULL!
        			printf("%c", result->buf[i]);
    			}
				free_password(result);
				break;
			}
		}
		else{
			//printf("\n%d PARENT: ", p);

		}
		if (r == 0){
			printf("\n%d CHILD: ", r);
			// Hash mit crack_hash versuchen zu knacken
			if (crack_hash(hash) != NULL){
				pwd * result = crack_hash(hash);
				printf("\nPASSWORD: ");
				for (int i = 0; i < pwd_maxlen; i++){
					// TODO print password if found, test with crack_hash == NULL!
        			printf("%c", result->buf[i]);
    			}
				free_password(result);
				break;
			}
		}
		else{
			//printf("\n%d PARENT: ", p);

		}
		
		
	}

	free_hashes(loaded_hashes);
	
	return 0;
}


// Versucht den Hash zu cracken, indem systematisch Passwörter generiert werden
// und darauf getestet wird, ob deren Hash mit hash übereinstimmt
// Returns pwd or NULL if no password was found
pwd *crack_hash(char *hash) {
	// Create new password
	pwd *password = new_password(pwd_maxlen);

	// Generate tempsting so password won't get affected by hashing, compare tempstring with the extracted hash
	char *tempstring = password->buf;
	tempstring = sha256(tempstring);
	test_string(tempstring, hash);

	//printf("\nempty password: \n");
	//for (int i = 0; i < password->buflen; i++){
	//	    printf("%c", password->buf[i]);
    //    }
	
	//printf("\n");
	
	int dead_end = next_password(password); // Create dead_end from return of next_password as while loop breaker
	while (dead_end != 0){
		
		//for (int i = 0; i < password->buflen; i++){
		//    printf("%c", password->buf[i]);
        //}

		tempstring = password->buf;
		tempstring = sha256(tempstring);
		if (test_string(tempstring, hash) == 0){
			return password;
		}
        dead_end = next_password(password);
		//printf("\n");
    }
	free_password(password);
		
	return NULL;
	
}

// Berechnet den Hash von string und gibt 1 zurück, wenn er mit hash übereinstimmt, sonst 0
int test_string(char *string, char *hash) {

	for (int i = 0; i < 64; i++){ // Size of Hash is 64
		//printf("%c", string[i]);
		//printf(" || ");
		//printf("%c", hash[i]);
		if (string[i] != hash[i]){
			return 1;
		}
	}
	//printf("SUCCESS");
	return 0;
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
	int n = 0;
	for (int i = 0; i < max_workers; i++) {
		// TODO
		n = max_workers;
		// check if process still running
		// if finished
		worker[i] = 0;
		n = n -1;

	}
	
	return n;
}

