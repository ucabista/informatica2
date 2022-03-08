#include <stdio.h>
#include <stdlib.h>

// malo, en revision

void heapify(int arr[], int n, int i)
{
	int largest = i; // Inicializar m�s grande como ra�z
	int l = 2 * i + 1; // Izquierdo = 2 * i + 1
	int r = 2 * i + 2; // derecha = 2*i + 2

	// Si el ni�o izquierdo es m�s grande que la ra�z
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Si es correcta es m�s grande que la m�s grande hasta ahora
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Si el m�s grande no es ra�z
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Apila de forma recursiva el sub�rbol afectado
		heapify(arr, n, largest);
	}
}

// funci�n principal para ordenar el mont�n
void heapSort(int arr[], int n)
{
	// Construir mont�n (reorganizar la matriz)
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Uno por uno extrae un elemento del mont�n
	for (i =n-1; i > 0; i--) {
		// Mover la ra�z actual al final
		swap(arr[0], arr[i]);

		// llamar a max heapify en el mont�n reducido
		heapify(arr, i, 0);
	}
}

/* Una funci�n de utilidad para imprimir una matriz de tama�o n */
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

