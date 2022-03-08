#include <stdio.h>


/*Una función de utilidad para intercambiar dos elementos*/
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta función toma el último elemento como pivote, coloca
el elemento pivote en su posición correcta en ordenados
matriz, y coloca todos más pequeños (más pequeños que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivote
	int i = (low - 1); // Índice de elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
	int j;
	for (j = low; j <= high - 1; j++)
	{
		// Índice de elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
		if (arr[j] < pivot)
		{
			i++; // índice de incremento del elemento más pequeño
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* La función principal que implementa QuickSort
arr [] -> Matriz a ordenar,
bajo -> Índice de inicio,
alto -> índice de finalización */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi es índice de partición, arr [p] es ahora
en el lugar correcto */
		int pi = partition(arr, low, high);

		// Ordene los elementos por separado antes
		// partición y después de la partición
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Función para imprimir una matriz */
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



