#include <stdio.h>
 
// Funcion para imprimir los elementos del arreglo
void print(int a[], int n)
{
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
 
// Funcion reversa para los elementos del arreglo
void reverse(int a[], int n)
{
	int low,high;
    for (low = 0, high = n - 1; low < high; low++, high--)
    {
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
    }
}
 
int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a)/sizeof(a[0]);
 
    reverse(a, n);
    print(a, n);
 
    return 0;
}
