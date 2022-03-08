void mover_ceros(int a[], int n)
{
    int count = 0;  
    int i;
    for (i = 0; i < n; i++)
        if (a[i] != 0)
            a[count++] = a[i]; 
    while (count < n)
        a[count++] = 0;
}
 
int main()
{
    int a[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n=sizeof(a) / sizeof(a[0]);
    mover_ceros(a, n);
    printf("ceros desplazados: ");
    int i;
    for(i=0;i<n;i++){
    	printf("%i ",a[i]);
	}
      
    return 0;
}
