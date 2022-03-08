#include <stdio.h>
#include <stdlib.h>

// malo, en revision

void heapify(int arr[], int n, int i)
{
	int largest = i; // Inicializar más grande como raíz
	int l = 2 * i + 1; // Izquierdo = 2 * i + 1
	int r = 2 * i + 2; // derecha = 2*i + 2

	// Si el niño izquierdo es más grande que la raíz
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Si es correcta es más grande que la más grande hasta ahora
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Si el más grande no es raíz
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Apila de forma recursiva el subárbol afectado
		heapify(arr, n, largest);
	}
}

// función principal para ordenar el montón
void heapSort(int arr[], int n)
{
	// Construir montón (reorganizar la matriz)
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Uno por uno extrae un elemento del montón
	for (i =n-1; i > 0; i--) {
		// Mover la raíz actual al final
		swap(arr[0], arr[i]);

		// llamar a max heapify en el montón reducido
		heapify(arr, i, 0);
	}
}

/* Una función de utilidad para imprimir una matriz de tamaño n */
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i){
		printf("%i ",arr[i]);
	}
		
	
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	printf("Arreglo ordenado es: \n\n");
	printArray(arr, n);
	
	return 0;
}

