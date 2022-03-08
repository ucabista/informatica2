// Escriba un algoritmo en pseudo código, para verificar si un número es par o impar
// Lenguaje C
#include <stdio.h>

int main(){
	
	int numero=0;
	
printf("Ingrese un numero para verificar si es par o no");
scanf("%i",&numero);

if(numero % 2 == 0){
	printf("El numero es par");
}else{
	printf("El numero es impar");
}
	
return 0;	
}
