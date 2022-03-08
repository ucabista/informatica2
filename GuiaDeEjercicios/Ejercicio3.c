// Escriba un algoritmo en pseudo código, para verificar si un número es primo
// Lenguaje C, un numero primo es aquel que solo es divisible entre el mismo y el 1
#include <stdio.h>

int main(){
	
	int numero=0,i=1,contador=0;
	
	printf("Introduzca un numero para verificar si es primo \n");
	scanf("%i",&numero);
	
	for(i=1;i<=numero;i++){
	
	if(numero % i ==0){
		contador++;
	}
			
	}
	
	if(contador==2){ // quiere decir que solo se divide por el 1 y el mismo
		printf("El numero %i es primo",numero);
	}else{
		printf("El numero %i no es primo",numero);
	}
	
	
	
	return 0;
}
