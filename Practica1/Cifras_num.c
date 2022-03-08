/*c. Calcular la cantidad de dígitos de un número positivo*/

#include<stdio.h>

int main(){
	
	int num=0,aux=0,cifras;
	
	
	printf("ingrese por pantalla un numero positivo");
	scanf("%i",&num);
	
	if(num<=0){
		printf("Usted ingreso un numero no valido");
	}else{
		
		aux=num;
		
		cifras=0;
		
		while(aux>0){
			num /= 10;
			aux=num;
			cifras++;
			
			}
		
		printf("El numero de cifras es: %i",cifras);
	}
	
	return 0;
}
