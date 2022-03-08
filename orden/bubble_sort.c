
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Una funci�n para implementar la clasificaci�n de burbujas
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)	

	// Los �ltimos elementos i ya est�n en su lugar
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

/* Funci�n para imprimir un arreglo */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("arreglo ordenado: \n");
	printArray(arr, n);
	return 0;
}

