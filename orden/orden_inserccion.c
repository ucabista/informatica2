// C program for insertion sort
#include <math.h>
#include <stdio.h>

/* Función para ordenar una matriz usando la ordenación por inserción*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Mover elementos de arr [0..i-1], que son
mayor que la clave, a una posición por delante
de su posición actual */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// Una función de utilidad para imprimir una matriz de tamaño n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printf("arreglo ordenado \n");
	printArray(arr, n);

	return 0;
}

