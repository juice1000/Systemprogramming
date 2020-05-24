#include "pwgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int next_pwd_internal(char *shifted_buffer, int remaining_buff_size);

pwd *new_password(int maxlen) {
	pwd *passw = malloc(sizeof(pwd));
	passw->buflen=maxlen+1;
	passw->buf = malloc(sizeof(char)*maxlen);

    printf("Generated!\n");

	return passw;
}

/**
 * Berechnet das nachfolgende Passwort.
 * Funktioniert wie ein Stellenwertsystem,
 * allerdings ist das 'niederwertigste' Zeichen links statt rechts
 *
 * RETURN: 1, wenn nächstes Passwort erfolgreich generiert wurde
 *         0, sonst (z.B. maximale Länge erreicht)
 */
int next_password(pwd *thepwd) {
	return next_pwd_internal(thepwd->buf, thepwd->buflen);
}

int next_pwd_internal(char *shifted_buffer, int remaining_buff_size) {
	if (shifted_buffer[0] == '\0') {
		if (remaining_buff_size > 1) {
			shifted_buffer[0] = 'a';
			shifted_buffer[1] = '\0';
			return 1;
		} else {
			return 0;
		}
	}
	
	/**
	 * Wenn der char in shifted_buffer[0] 0-8, oder a-y ist,
	 * dann soll shifted_buffer[0] auf den entsprechend nächsten char gesetzt werden,
	 * also z.B. f wird zu g und 5 wird zu 6.
	 *
	 * Beenden Sie anschließend die Funktion mit Rückgabewert 1.
	 *
	 * Eine ASCII Tabelle kann Ihnen helfen.
	*/

	if ((shifted_buffer[0] >= '0' && shifted_buffer[0] < '9') || (shifted_buffer[0] >= 'a' && shifted_buffer[0] < 'z')){
		//shift value to next
		shifted_buffer[0] = shifted_buffer[0]+1;
		return 1;
	}
	
	/**
	 * Wenn der char in shifted_buffer[0] ein z ist, dann soll
	 * shifted_buffer[0] auf den character '0' gesetzt werden.
	 * Verwechseln Sie '0' nicht mit dem Nullbyte '\0'.
	 *
	 * Beenden Sie anschließend die Funktion mit Rückgabewert 1.
	 */
	if (shifted_buffer[0] == 'z'){
		shifted_buffer[0] = '0';
		return 1;
	}
	
	
	// Wenn der char in shifted_buffer[0] eine '9' ist, dann wird die nächste Stelle bearbeitet
	if (shifted_buffer[0] == '9') {
		int retval = next_pwd_internal(shifted_buffer+1, remaining_buff_size-1);
		if (retval) {
			shifted_buffer[0] = 'a';
		}
		return retval;
	}
	
	return 0;
}

void free_password(pwd *thepwd) {
	//TODO
	
	free(thepwd);
}


int main(){
	
	pwd *pass = new_password(4);
	printf("%d Buflen\n", pass->buflen);
	printf("LOAD NEW HASH:");
			
	for (int i = 0; i < pass->buflen; i++){
			printf("%c empty pass: ", pass->buf[i]);
		}

	for (int j = 0; j < 100000; j++){
		int check = next_password(pass);
		printf("NEXT \n");
		for (int i = 0; i < pass->buflen-1; i++){
				printf("%c pass: ", pass->buf[i]);
			}
	}
		

	//printf("%c Buffer \n", *pass->buf);
	//printf("%p\n", )
	//pass->buf[0] = 'a';
	//pass->buf[1] = 'b';
	//printf("%d Buffer \n", pass->buf[0]);
	//
	//while (check != 0){
	//	sleep(3);
	//	for (int i = 0; i < pass->buflen; i++){
	//		printf("%c ", pass->buf[i]);
	//	}
	//	//sleep(1);
	//	printf(" || ");
//
	//	check = next_password(pass);
	//}

    return 0;
}