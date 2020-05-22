#include "bruteforcer.h"

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
	// TODO
	loaded_hashes = load_hashes(filename);

	// Main loop -> Iteriert über alle Hashes
	for (int i = 0; i < loaded_hashes->len; i++) {
		char *hash = loaded_hashes->array[i];
		
		// Hash mit crack_hash versuchen zu knacken
		// TODO
		if (crack_hash(hash) != NULL){
			for (int i = 0; i < sizeof(loaded_hashes); i++){
        		printf("%s\n",loaded_hashes->array[i]);
    		}
		}

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
	pwd *password = new_password(pwd_maxlen);
	test_string(password->buf, hash);
	
	while (next_password(password) != 0){
		next_password(password);
		password->buf = sha256(password->buf);
		if (test_string(password->buf, hash) == 0){
			return password;
		}
			

	}
		
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
	for (int i = 0; i < sizeof(string); i++){
		if (string[i] != hash[i]){
			//printf("FAILED");
			return 1;
		}
	}
	printf("SUCCESS");
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

