#include<stdio.h>

int reverse(int numero, int acum){
	if (numero<10)
		return acum;
	else
		return reverse(numero/10,acum*10+numero/10%10);
		
}

int main(){
	int number;
	
	printf("Numero original: ");
	scanf("%i",&number);
	printf("\nNumero invertido: %i", reverse(number,number%10));
	
	return 0;
}
