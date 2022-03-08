#include<stdio.h>

#define T 8

void invertir(int a[], int n) {
	int i, j, t;
	
	for (i=0, j=n-1; i<n-1 && i<j; i++) {
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		j--;
	}
} //Fin invertir

void reverse_re(int a[], int begin, int end) {
	int t;
	
	t=a[begin];
	a[begin]=a[end];
	a[end]=t;
	
	if (begin<end && begin!=end-1) 
		reverse_re(a,begin+1,end-1)	;
}

void imprimir(int a[],int n){
	int i;
	
	for (i=0; i<n; i++) {
		printf("%i ",a[i]);
	}	
	printf("\n");
} //Fin imprimir


int main() {
	int array[T];
	int size, i;
	
	for (i=0; i<T; i++) 
		array[i]=i+1;
	
	size = sizeof(array)/4;  //Un entero ocupa 4 bytes
	
	printf("Arreglo original: ");
	imprimir(array, size);
	
	invertir(array,size);
	printf("Arreglo invertido: ");
	imprimir(array, size);
	
	printf("Arreglo invertido pero recursivo: ");
	reverse_re(array,0,size-1);
	imprimir(array, size);
	
	return 0;
}
