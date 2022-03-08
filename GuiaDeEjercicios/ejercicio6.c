#include <stdio.h>
//ejercicio 6
// Escriba un programa que C, que lea dos enteros y escriba su suma.
int main(){
	
	int num1,num2,resultado=0;
	
	printf("Escriba dos numeros enteros \n");
	scanf("%i %i",&num1,&num2);
	
	resultado = num1 + num2;
	
	printf("el resultado de la suma es %i",resultado);
	
	return 0;
}
