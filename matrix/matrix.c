#include <stdio.h>
#include <stdlib.h>

void addMatrix(int **matrix1, int **matrix2, int size);
int** array(int size);
void printMatrix(int **matrix, int size);

void main(int argc, char *argv)
{
	int size;
	int i,j;
	int **matrix1, **matrix2;
	printf("size of matirx: ");
	scanf("%d",&size);
	matrix1 = array(size);
	matrix2 = array(size);

	printMatrix(matrix1, size);
	printMatrix(matrix2, size);

 	addMatrix(matrix1, matrix2, size);
	printMatrix(matrix1, size);
	
	free(matrix1[0]);
	free(matrix1);

	free(matrix2[0]);
	free(matrix2);
}

void addMatrix(int **matrix1, int **matrix2, int size)
{
	int i,j;
	for(i = 0; i < size; i++)
	for(j = 0; j < size; j++)
		matrix1[i][j] += matrix2[i][j];
}

int ** array(int size)
{
	int **matrix;
	int i,j;
	matrix = (int **)malloc(size * sizeof(int *));
	for(i = 0; i < size; i++)
		matrix[i] = (int *)malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
	for(j = 0; j < size; j++)
		matrix[i][j] = rand()%10;

	return matrix;
}

void printMatrix(int **matrix, int size)
{
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ",matrix[i][j]);
		}
	printf("\n");
	}
}