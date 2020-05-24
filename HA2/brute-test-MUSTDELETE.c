#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
	// TODO: Vervollständigen
	int pwd_maxlen = (int) strtol(argv[1], (char **)NULL, 10);
	int max_workers = (int) strtol(argv[1], (char **)NULL, 10);
	filename = argv[3];

	// worker = ...
	// worker array mit 0 initialisieren
	// TODO
	//pid_t *worker = malloc(sizeof(pid_t) * max_workers);
	//// worker array mit 0 initialisieren
	//for (int i = 0; i < max_workers; i++){
	//	worker[i] = 0;
	//}
	

	INFO("\nBRUTEFORCER GESTARTET\n");
	INFO("---------------------\n");
	INFO("Maximale Passwortlänge: %d\n", pwd_maxlen);
	INFO("Anzahl der Worker: %d\n", max_workers);
	INFO("Hashes lesen aus Datei: %s\n", filename);
	INFO("---------------------\n\n");
	
	// Hashes in ein hashes struct laden
    pwd * password = new_password(pwd_maxlen);
    printf("empty passw: ");
	    for (int i = 0; i < password->buflen; i++){
		    printf("%c", password->buf[i]);
        }
	// TODO
	loaded_hashes = load_hashes(filename);

	// Main loop -> Iteriert über alle Hashes
	for (int i = 0; i < loaded_hashes->len; i++) {

        
		char *hash = loaded_hashes->array[i];
		printf("\n%d LOAD NEW HASH: ", i);
		sleep(3);
		// Hash mit crack_hash versuchen zu knacken
		// TODO
		//crack_hash(hash);
		char *tempstring = password->buf;
		tempstring = sha256(tempstring);

        for (int i = 0; i < 64 ;i++){
		    printf("%c", tempstring[i]);
        }
        printf("\n");
	
		for (int i = 0; i < sizeof(tempstring); i++){
		    printf("%c", tempstring[i]);
		    if (tempstring[i] != hash[i]){
		    	printf("FAILED");
		    	break;
		    }
            else{
                printf("SUCCESS");
            }
		}

        int dead_end = next_password(password);
	    printf("%d Dead_End_var:", dead_end);
	    while (dead_end != 0){
        
	    	for (int i = 0; i < password->buflen; i++){
	    	    printf("%c", password->buf[i]);
            }
    
	    	printf(" || ");
            tempstring = password->buf;
		    tempstring = sha256(tempstring);
	    	for (int i = 0; i < 64 ;i++){
		        printf("%c", tempstring[i]);
            }
            printf(" || ");

            for (int i = 0; i < 64 ;i++){
		        printf("%c", hash[i]);
            }
    
            printf(" || ");

		    for (int i = 0; i < sizeof(tempstring); i++){
		        printf("%c", tempstring[i]);
		        if (tempstring[i] != hash[i]){
		        	printf("FAILED");
		        	break;
		        }
                else{
                    printf("SUCCESS");
                }
		    }
            dead_end = next_password(password);


	    	printf("\n");
        }
        free_password(password);
        pwd * password = new_password(pwd_maxlen);
	    printf("empty passw: ");
	    for (int i = 0; i < password->buflen; i++){
		    printf("%c", password->buf[i]);
        }
		//if (crack_hash(hash) != NULL){
		//	for (int i = 0; i < sizeof(loaded_hashes); i++){
        //		printf("%s\n",loaded_hashes->array[i]);
    	//	}
		//}

		// Erfolg? -> print password
		// Fehlgeschlagen? -> Einfach weiter in der Schleife


		
	}
	
	
	// Aufräumen und beenden
	// TODO
	free_hashes(loaded_hashes);
	
	return 0;
}

// Versucht den Hash zu cracken, indem systematisch Passwörter generiert werden
// und darauf getestet wird, ob deren Hash mit hash übereinstimmt
// Returns pwd or NULL if no password was found
pwd *crack_hash(char *hash) {
	// Mit new_password() ein leeres Passwort anlegen
	int pwd_max = 4;
	printf("%d maxLen", pwd_max);
	pwd *password = new_password(pwd_max);
	
	for (int i = 0; i < password->buflen; i++){
		    printf("%c empty pass: ", password->buf[i]);
    }
	
	char *tempstring = password->buf;
	tempstring = sha256(tempstring);

	
	
	//int dead_end = next_password(password);
	//printf("%d Dead_End_var:", dead_end);
	//while (dead_end != 0){
	//	
	//	for (int i = 0; i < password->buflen; i++){
	//	    printf("%c", password->buf[i]);
    //    }
//
	//	printf(" || ");
//
	//	if (test_string(password->buf, hash) == 0){
	//		return password;
	//	}
    //    dead_end = next_password(password);
	//	//printf("\n");
    //}
		
	return NULL;
	// Mit test_string() überprüfen, ob das (zuerst leere) Passwort zum Hash passt
	// In einer Schleife next_password() aufrufen, und das nächste Passwort überprüfen
	// Schleifenabbruch, sobald next_password() 0 zurückgibt => es gibt kein weiteres Passwort,
	// d.h. alle Passwörter bis zur maximalen Länge wurden bereits generiert und überprüft
	// ODER
	// Schleifenabbruch, wenn das Passwort gefunden wurde
	// TODO
	
	// Aufräumen
	// TODO
	
	// Passwort nicht gefunden -> NULL zurückgeben
	// Passwort gefunden -> das Password zurückgeben
	// TODO
	
}

// Berechnet den Hash von string und gibt 1 zurück, wenn er mit hash übereinstimmt, sonst 0
int test_string(char *string, char *hash) {
	string = sha256(string);
	for (int i = 0; i < sizeof(string); i++){
		printf("%c", string[i]);
		if (string[i] != hash[i]){
			//printf("FAILED");
			return 1;
		}
	}
	printf("SUCCESS");
	return 0;
}

