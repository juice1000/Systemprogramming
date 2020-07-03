#include "matrix.h"

matrix* create_matrix(unsigned int m, unsigned int n, int* numbers)
{
	struct matrix *matrix = malloc(sizeof(struct matrix)*n*m);

	matrix->m = m;
	matrix->n = n;
	matrix->elements = malloc(sizeof(int)*m*n);
	for (int i = 0; i < n*m; i++){
		matrix->elements[i] = numbers[i];
	}

	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-neue Matrix erstellen und zurueckgeben (Pointer!!!)
			-(das Array soll dabei zwar kopiert, aber ansonsten UNVERAENDERT abgespeichert werden.
			  Dies ist für die automatischen Tests unerlaesslich)
	*/

	return matrix;
}

matrix* create_matrix_from_row(unsigned int m, unsigned int row_nr, matrix* row)
{
	/*TODO
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen einer neuen Matrix (Initialisierung mit 0)
			-Kopieren der gegebenen Zeile an die richtige Stelle
	*/

	// how to check if row matrix is really just one row??
	
	int size = sizeof(row)/ sizeof(row[0]);
	struct matrix *zeros = malloc(sizeof(struct matrix)*m*4);	//alloc matrix array
	memset(zeros, 0, m*4*sizeof(int));

	zeros->elements[row_nr] = row->elements;
	
	return zeros;
}

void free_matrix(matrix* matrix)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Matrix und alle dynamisch reservierten elemente der Matrix freigeben
	*/	

	//free(matrix->elements); --> gives segmentation fault
	//int size = sizeof(matrix->elements)/sizeof(int);
	//for (int i = 0; i <size; i++){
	//	free(matrix->elements[i]);
	//}
	free(matrix);
}

matrix* duplicate_matrix(matrix* old)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen und Zurückgeben einer NEUEN Matrix mit genau den selben Parametern der gegebenen Matrix
	*/

	int size = sizeof(old->elements)/sizeof(old->elements[0]);
	struct matrix *new = old;
	for (int i = 0; i <12; i++){
		printf("%d", new->elements[i]);
	}
	printf("%d\n", size);
	
	return new;
}

void add_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Addieren von a und b (a+b)
	*/
	int size = sizeof(a->elements)/sizeof(a->elements[0]);
	for (int i = 0; i <12; i++){
		a->elements[i] + b->elements[i];
	}
	printf("%d\n", size);
	
}	

void subtract_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Subtrahieren von a und b (a-b)
	*/
	int size = sizeof(a->elements)/sizeof(a->elements[0]);
	for (int i = 0; i <12; i++){
		a->elements[i] - b->elements[i];
	}
	printf("%d\n", size);
}

int get_elem_of_matrix(matrix* matrix, unsigned int i, unsigned int j)
{
	/*TODO
		-Argumente auf Gueltigkeit ueberpruefen
		-Rueckgabe des Elements an den Indizes i und j	
	*/
	return matrix->elements[i*j];
}

int check_matrix_elements(matrix* matrix)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Pruefen, ob die Elemente der Matrix <, > oder = 0 sind
			->sobald mindestens ein Element <0 ist, soll -1 zurückgegeben werden
			->wenn alle Elemente 0 sind, soll 0 zurückgegeben werden
			->ansonsten soll 1 zurückgegeben werden
	*/
	int check = 0;
	int size = sizeof(matrix->elements)/sizeof(matrix->elements[0]);
	for (int i = 0; i <12; i++){
		if (matrix->elements[i] <0){
			return -1;
		}
		else if (matrix->elements[i] > 0){
			check = 1;
		}
	}
	printf("%d\n", size);
	return check;
}

matrix* get_row_from_matrix(matrix* mat, unsigned int m)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Rueckgabe der m-ten Zeile der Matrix (Die Zeile selbst ist auch wieder eine Matrix mit genau einer Zeile)
	*/
	struct matrix * row;
	row->elements = mat->elements[m];
	for (int i = 0; i <3; i++){
		row->elements[i];
	}

	return row;

}

void print_matrix(matrix* matrix)
{
	if(matrix == NULL)
	{
		printf("ERROR: print_matrix() | given matrix is NULL\n");
		return;
	}


	//determines the largest element (for formatting the output with field widths)
	int max = get_elem_of_matrix(matrix, 0,0);	
	for(int i = 0; i< matrix->m; i++)
	{
		for(int j = 0; j < matrix->n; j++)
		{
			int current = get_elem_of_matrix(matrix, i,j);
			max = (current>max) ? current : max;
		}
	}

	int grade = 1;	//represents the number of digits of the largest element (for formatting the output with field widths)
	while(max > 9)
	{
		max/=10;
		grade++;
	}

	//prints upper line
	printf(" ");
	for(int i = 0; i< ((grade + 1)*matrix->n +1); i++)
	{
		printf("-");
	}
	printf("\n");

	//prints body
	for(int i = 0; i< matrix->m; i++)
	{
		printf("| ");
		for(int j = 0; j < matrix->n; j++)
		{
			printf("%*i ", grade, get_elem_of_matrix(matrix, i, j));
		}
		printf("|\n");
	}

	//prints lower line
	printf(" ");
	for(int i = 0; i< ((grade + 1)*matrix->n +1); i++)
	{
		printf("-");
	}
	printf("\n");
}


/*TODO:
	Hier koennen bei Bedarf eigene Funktionen implementiert werden
*/
