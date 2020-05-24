#include "pwgen.h"

int next_pwd_internal(char *shifted_buffer, int remaining_buff_size);

pwd *new_password(int maxlen) {
	pwd *passw = malloc(sizeof(pwd));
	passw->buflen=maxlen+1;
	passw->buf = malloc(sizeof(char)*maxlen);

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

	free(thepwd->buf);
	free(thepwd);
}
