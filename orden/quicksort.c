#include <stdio.h>


/*Una funci�n de utilidad para intercambiar dos elementos*/
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta funci�n toma el �ltimo elemento como pivote, coloca
el elemento pivote en su posici�n correcta en ordenados
matriz, y coloca todos m�s peque�os (m�s peque�os que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivote
	int i = (low - 1); // �ndice de elemento m�s peque�o e indica la posici�n correcta del pivote encontrado hasta ahora
	int j;
	for (j = low; j <= high - 1; j++)
	{
		// �ndice de elemento m�s peque�o e indica la posici�n correcta del pivote encontrado hasta ahora
		if (arr[j] < pivot)
		{
			i++; // �ndice de incremento del elemento m�s peque�o
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* La funci�n principal que implementa QuickSort
arr [] -> Matriz a ordenar,
bajo -> �ndice de inicio,
alto -> �ndice de finalizaci�n */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi es �ndice de partici�n, arr [p] es ahora
en el lugar correcto */
		int pi = partition(arr, low, high);

		// Ordene los elementos por separado antes
		// partici�n y despu�s de la partici�n
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Funci�n para imprimir una matriz */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%i ",arr[i]);
	
}


int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("arreglo ordenado");
	printArray(arr, n);
	return 0;
}



