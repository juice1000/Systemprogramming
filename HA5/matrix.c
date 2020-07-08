#include "matrix.h"

matrix* create_matrix(unsigned int m, unsigned int n, int* numbers)
{
	matrix *mat = (matrix*)malloc(sizeof(matrix));
	int size = n*m;
	for (int i = 0; i <size; i++){ // Alles checken!
		if (numbers[i] <0){
			printf("negative values!\n");
			return NULL;
		}
	}
	
	mat->m = m;
	mat->n = n;
	mat->elements = malloc(sizeof(int)*m*n);
	for (int i = 0; i < size; i++){
		mat->elements[i] = numbers[i];
	}

	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-neue Matrix erstellen und zurueckgeben (Pointer!!!)
			-(das Array soll dabei zwar kopiert, aber ansonsten UNVERAENDERT abgespeichert werden.
			  Dies ist für die automatischen Tests unerlaesslich)
	*/

	return mat;
}

matrix* create_matrix_from_row(unsigned int m, unsigned int row_nr, matrix* row)
{
	/*TODO
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen einer neuen Matrix (Initialisierung mit 0)
			-Kopieren der gegebenen Zeile an die richtige Stelle
	*/
	
	// how to check if row matrix is really just one row??
	if (row == NULL){
		printf("Given matrix is empty\n");
		return NULL;
	}

	matrix* zeros = (matrix*)malloc(sizeof(matrix));	//alloc matrix array
	zeros->m = m;
	zeros->n = row->n;
	zeros->elements = calloc(1, sizeof(int)*m*zeros->n);
	int size_zeros = zeros->m * row->n;
	int row_count = 0;

	for(int i = 0; i<size_zeros; i++){

		if (i % row->n == 0 && i != 0){
			row_count++;
		}
		if (row_count == row_nr){
			for (int j = 0; j < row->n; j++){
				zeros->elements[i] = row->elements[j];
				i++;
			}
			break;
		}
		
	}
	return zeros;
}

void free_matrix(matrix* matrix)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Matrix und alle dynamisch reservierten elemente der Matrix freigeben
	*/	
	if(matrix == NULL){
		return;
	}
	free(matrix->elements);
	free(matrix);
}

matrix* duplicate_matrix(matrix* old)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Erstellen und Zurückgeben einer NEUEN Matrix mit genau den selben Parametern der gegebenen Matrix
	*/
	if(old == NULL){
		return NULL;
	}
	int size = old->m * old->n;
	struct matrix *new = old;
	for (int i = 0; i <size; i++){
		printf("%d", new->elements[i]);
	}
	
	return new;
}

void add_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Addieren von a und b (a+b)
	*/
	if (a == NULL || b == NULL){
		printf("Given matrizes are empty\n");
		return;
	}
	int size = a->m * a->n;

	for (int i = 0; i <size; i++){
		a->elements[i] = a->elements[i] + b->elements[i];
	}
	
}	

void subtract_matrix(matrix* a, matrix* b)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Elementweises Subtrahieren von a und b (a-b)
	*/
	if (a == NULL || b == NULL){
		printf("Given matrizes are empty\n");
		return;
	}
	int size = a->m * a->n;
	for (int i = 0; i <size; i++){
		a->elements[i] = a->elements[i] - b->elements[i];
	}
}

int get_elem_of_matrix(matrix* matrix, unsigned int i, unsigned int j)
{
	/*TODO
		-Argumente auf Gueltigkeit ueberpruefen
		-Rueckgabe des Elements an den Indizes i und j	
	*/
	if (i > matrix->m || i<0 || j<0 || j>matrix->n){
		printf("Out of bounds");
		return -1;
	}
	int size = matrix->m * matrix->n;
	int row_count = 0;
	int col_count = 0;
	for (int k = 0; k < size; k++){
		
		if(k % matrix->n == 0 && k != 0){
			row_count++;
			col_count = 0;
		}
		if(row_count == i){
			for (int z = 0; z < matrix->n; z++){
				if(col_count == j){
					return matrix->elements[k];
				}	
				k++;
				col_count++;
			}			
		}
		col_count++;
	}
	
	return -1;
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
	if(matrix == NULL){
		return -1;
	}
	int check = 0;
	int size = matrix->m * matrix->n;
	for (int i = 0; i <size; i++){
		if (matrix->elements[i] <0){
			return -1;
		}
		else if (matrix->elements[i] > 0){
			check = 1;
		}
	}
	return check;
}

matrix* get_row_from_matrix(matrix* mat, unsigned int m)
{
	/*TODO:
			-Argumente auf Gueltigkeit ueberpruefen
			-Rueckgabe der m-ten Zeile der Matrix (Die Zeile selbst ist auch wieder eine Matrix mit genau einer Zeile)
	*/

	if(mat == NULL || m < 0 || m > mat->m){
		return NULL;
	}

	matrix * row = (matrix*)malloc(sizeof(matrix));
	row->m = 1;
	row->n = mat->n;
	row->elements = calloc(1, sizeof(int)*mat->n);
	int size = mat->n * mat->m;
	int row_count = 0;
	for(int i = 0; i<size; i++){
		if (i % mat->n == 0 && i != 0){
			row_count++;
		}
		if (row_count == m){
			
			for (int j = 0; j < row->n; j++){
				row->elements[j] = mat->elements[i];
				i++;
			}
			break;
		}
		
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
