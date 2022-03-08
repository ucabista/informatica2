#include <stdio.h>
//Guia ejercicio1
//Escriba un algoritmo en pseudo código, para determinar el mayor de tres numeros
// esto esta en lenguaje C
int main(void){
	
	int n1,n2,n3;
	
	n1=n2=n3=0; // inicializar
	
	printf("Ingrese por pantalla tres numeros enteros: ");
	scanf("%i %i %i",&n1,&n2,&n3);
	
	
	// si n1 es mayor
	if(n1>n2 && n1>n3){
		printf("El numero mayor es %i",n1);
	}else if(n2>n1 && n2>n3){ // si n2 es mayor
		printf("El numero mayor es %i",n2);
	}else{ // si n3 es mayor
		printf("El numero mayor es %i",n3);
	}

	
	
}
