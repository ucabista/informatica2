#include <stdio.h>

/* ffunci�n para ordenar arr usando shellSort */
int shellSort(int arr[], int n)
{
	// Comience con una gran brecha, luego reduzca la brecha
	int gap;
	for (gap = n/2; gap > 0; gap /= 2)
	{
		// Realice una ordenaci�n por inserci�n con huecos para este tama�o de hueco.
// Los primeros elementos de espacio a [0..gap-1] ya est�n en orden de espacio
// sigue agregando un elemento m�s hasta que toda la matriz est�
// espacio ordenado
		int i;
		for (i = gap; i < n; i += 1)
		{
			// agrega una [i] a los elementos que han sido ordenados por espacios
			// guarda un [i] en temp y haz un agujero en la posici�n i
			int temp = arr[i];

		// desplazar elementos anteriores ordenados por espacios hasta el correcto
// se encuentra la ubicaci�n de una [i]
			int j;		
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			// poner temp (el original a [i]) en su ubicaci�n correcta
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("%i",arr[i]);
}

int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("arreglo dedordenado: \n\n");
	printArray(arr, n);

	shellSort(arr, n);
	printf("\n\n");
	printf("arreglo ordenado: \n\n");
	printArray(arr, n); 

	return 0;
}

