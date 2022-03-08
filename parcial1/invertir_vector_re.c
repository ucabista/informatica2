#include <stdio.h>
 
// Function to print contents of an array
void print(int a[], int n)
{
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
 
// funcion recursiva
void reverse(int a[], int low, int high)
{
    if (low < high)
    {
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
 
        reverse(a, low + 1, high - 1);
    }
}
 
int main(void)
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a)/sizeof(a[0]);
 
    reverse(a, 0, n - 1);
    print(a, n);
 
    return 0;
}
