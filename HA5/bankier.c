#include "bankier.h"

int check_initial_state(matrix* f, matrix* G)
{
	/*TODO
			Testen, ob ZU BEGINN kein Prozess mehr Resourcen benötigt, als insgesamt verfügbar sind
			Wird nur genau einmal aufgerufen
	
			Muss nicht extra aufgerufen werden, das übernimmt die main()
	*/

	return 0;
}

int check_allocation(matrix* B, matrix* R, matrix* f, matrix* allocation, unsigned int ID)
{
	/*TODO:
			-Testen, ob überhaupt genügend Ressourcen vorhanden sind, um Anforderung zu erfüllen
			-"virtuelle Umgebung" für den Bankieralgorithmus schaffen
			-Bankieralgorithmus aufrufen
			-Bei Erfolg: Anforderung erfüllen und ggf. den Prozess 
			 beenden (Belegungen wieder freigeben, Restanforderung auf 0 setzen)
			->Ansonsten den Prozess "blockieren" (0 zurückgeben. Das Blockieren wird dann von der main() übernommen)
			-Erinnerung: dynamisch reservierter Speicher muss wieder freigegeben werden!
	*/

	return 0;
}

int check_state(matrix* B, matrix* R, matrix* f)
{
	/*TODO:
			-Bankieralgorithmus implementieren
	*/

	return -1;
}

//===============================================================================

/*TODO:
	Hier koennen bei Bedarf eigene Funktionen implementiert werden
*/


//===============================================================================

int abs(int n)
{
	return (n>0) ? n : -n;
}

void print_BRf(matrix* B, matrix* R, matrix* f)
{
	unsigned int m = B->m;
	unsigned int n = B->n;

	if(B==NULL || R==NULL || f==NULL)
	{
		printf("ERROR: print_BRf() | given matrices = NULL.\n");
		return;
	}

	if(f->m != 1 || f->n != n || R->m !=m || R->n != n)
	{
		printf("ERROR: print_BRf() | given matrices dont have matching dimensions.\n");
		return;
	}

	int max_B = get_elem_of_matrix(B, 0,0);		//largest elements
	int max_R = get_elem_of_matrix(R, 0,0);
	int max_f = get_elem_of_matrix(f, 0,0);

	int grade_B = 1;	//represents the number of digits of the largest element
	int grade_R = 1;
	int grade_f = 1;

	int width_B;
	int width_R;
	int width_f;


	for(unsigned int i = 0; i< B->m; i++)
	{
		for(unsigned int j = 0; j < B->n; j++)
		{
			int current = get_elem_of_matrix(B, i,j);
			max_B = (abs(current)>max_B) ? current : max_B;
		}
	}

	for(unsigned int i = 0; i< R->m; i++)
	{
		for(unsigned int j = 0; j < R->n; j++)
		{
			int current = get_elem_of_matrix(R, i,j);
			max_R = (abs(current)>max_R) ? current : max_R;
		}
	}

	for(unsigned int j = 0; j < f->n; j++)
	{
		int current = get_elem_of_matrix(f, 0,j);
		max_f = (abs(current)>max_f) ? current : max_f;
	}

	if(max_B < 0) grade_B++;
	while(max_B > 9 || max_B < -9)
	{
		max_B/=10;
		grade_B++;
	}
	width_B = 3 + n*(grade_B+1);

	if(max_R < 0) grade_R++;
	while(max_R > 9 || max_R < -9)
	{
		max_R/=10;
		grade_R++;
	}
	width_R = 3 + n*(grade_R+1);

	if(max_f < 0) grade_f++;
	while(max_f > 9 || max_f < -9)
	{
		max_f/=10;
		grade_f++;
	}
	width_f = 3 + n*(grade_f+1);

	//print upper line (B: R: f:)
	for(int i = 0; i < width_B + width_R + width_f + 2*3; i++)
	{
		if(i==(int)((width_B-1)/2)) printf("B");
		else if(i==(int)(width_B + 3 + (width_R-1)/2)) printf("R");
		else if(i==(int)(width_B + 3 + width_R + (width_f-1)/2)) printf("f");
		else printf(" ");
	}
	printf("\n");

	//================================ print B ================================= 
	//prints upper line
	printf(" ");
	for(int i = 0; i< width_B-2; i++) 	printf("-");

	printf("\n");

	//prints body
	for(unsigned int i = 0; i< m; i++)
	{
		printf("| ");
		for(unsigned int j = 0; j < n; j++)
		{
			int elem = get_elem_of_matrix(B, i, j);
			if(blocked_processes[i]) printf("\033[1;31m%*i\033[0m ", grade_B, elem);
			else if(elem < 0) printf("\033[1;33m%*i\033[0m ", grade_B, elem);
			else 		 printf("%*i ", grade_B, elem);
			
		}
		printf("|\n");
	}

	//prints lower line
	printf(" ");
	for(int i = 0; i< width_B-2; i++)	printf("-");
	
	printf("\r\033[%iC\033[%iA", (width_B+3), (m+1));	//move curser forwards and upwards

	//================================ print R ================================= 
	//prints upper line
	printf(" ");
	for(int i = 0; i< width_R-2; i++) 	printf("-");

	printf("\033[%iD\033[%iB", (width_R-1), 1);		//move curser backwards and downwards

	//prints body
	for(int i = 0; i< m; i++)
	{
		printf("| ");
		for(int j = 0; j < n; j++)
		{
			int elem = get_elem_of_matrix(R, i, j);
			if(blocked_processes[i]) printf("\033[1;31m%*i\033[0m ", grade_R, elem);
			else if(elem < 0) printf("\033[1;33m%*i\033[0m ", grade_R, elem);
			else 		 printf("%*i ", grade_R, elem);
		}
		printf("|\033[%iD\033[%iB", width_R, 1);	//move curser backwards and downwards
	}

	//prints lower line
	printf(" ");
	for(int i = 0; i< width_R-2; i++)	printf("-");
	
	printf("\033[%iC\033[%iA", 4, (int)(m/2 +2));		//move curser forwards and upwards


	//================================ print f ================================= 
	//prints upper line
	printf(" ");
	for(int i = 0; i< width_f-2; i++) 	printf("-");

	printf("\033[%iD\033[%iB", (width_f-1), 1);		//move curser backwards and downwards

	//prints body
	printf("| ");
	for(int j = 0; j < n; j++)
	{
		int elem = get_elem_of_matrix(f, 0, j);
		if(elem < 0) printf("\033[1;33%*i\033[0m ", grade_f, elem);
		else 		 printf("%*i ", grade_f, elem);
	}
	printf("|\033[%iD\033[%iB", width_f, 1);	//move curser backwards and downwards

	//prints lower line
	printf(" ");
	for(int i = 0; i< width_f-2; i++)	printf("-");
	
	printf("\r\033[%iB\n\n", (int)(m/2 +1));	//move curser backwards and downwards

}