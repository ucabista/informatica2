#include <stdio.h>

// ORDENAMIENTO POR INTERCAMBIO - BURBUJA
void swap1(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Una funci�n para implementar la clasificaci�n de burbujas
void intercambio(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)	

	// Los �ltimos elementos i ya est�n en su lugar
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap1(&arr[j], &arr[j+1]);
}


void swap2(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	//L�mite de movimiento uno por uno del subarreglo sin clasificar
	for (i = 0; i < n-1; i++)
	{
		// Encuentra el elemento m�nimo en una matriz sin clasificar
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Intercambia el elemento m�nimo encontrado con el primer elemento
		swap2(&arr[min_idx], &arr[i]);
	}
}


// Fin funcion ordenamiento por seleccion

// funcion ordenamiento por inserccion

/* Funci�n para ordenar una matriz usando la ordenaci�n por inserci�n*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Mover elementos de arr [0..i-1], que son
mayor que la clave, a una posici�n por delante
de su posici�n actual */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


// Fin funcion de ordenamiento por inserccion



/*Una funci�n de utilidad para intercambiar dos elementos*/
void swap4(int* a, int* b)
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
			swap4(&arr[i], &arr[j]);
		}
	}
	swap4(&arr[i + 1], &arr[high]);
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
		
		printf("\n\n");
	
}


int main()
{
	// un arreglo desornado para cada tipo de algoritmo de ordenamiento
	int arr1[] = { 20, 34, 11, 54, 33, 10, 15, 55, 99, 40};
	int arr2[] = { 20, 34, 11, 54, 33, 10, 15, 55, 99, 40};
	int arr3[] = { 20, 34, 11, 54, 33, 10, 15, 55, 99, 40};
	int arr4[] = { 20, 34, 11, 54, 33, 10, 15, 55, 99, 40};
	
	int longitud = sizeof(arr1) / sizeof(arr1[0]); // longitud del arreglo
	
	intercambio(arr1,longitud);
	printf("Arreglo ordenado por Intercambio: \n");
	printArray(arr1, longitud);
	
	selectionSort(arr2, longitud);
	printf("Arreglo ordenado por Seleccion: \n");
	printArray(arr2, longitud);
		
	insertionSort(arr3, longitud);
	printf("arreglo ordenado por Inserccion: \n");
	printArray(arr3, longitud);

	quickSort(arr4, 0, longitud - 1);
	printf("arreglo ordenado por Quicksort: \n ");
	printArray(arr4, longitud);
	
	
	return 0;
}



