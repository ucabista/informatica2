/*b. Dado un arreglo de enteros retorne el mayor, menor y el
promedio. */
#include<stdio.h>

int main(){
	
	int i,miArreglo[5]={0,1,2,3,6};
	int mayor=1,menor=999,aux=0,alto=0,bajo=0;
	
	float prom=0,suma=0;
	
	
	
	for(i=0;i<5;i++){
		
		suma += miArreglo[i]; // suma de numeros
		
		// calcular menor
		if(miArreglo[i]<menor){
			aux=miArreglo[i];
			
			if(aux<bajo){
				bajo=aux;
			}
		}
		
		// calcular mayor
		if(miArreglo[i]>mayor){
			aux=miArreglo[i];
			
			if(aux>alto){
				alto=aux;
			}
			
		}
		
	}
	
	prom = suma  / 5;
	
	printf("El promedio de los numeros es %2.f \n",prom);
	printf("El numero mayor de los numeros es %i \n",alto);
	printf("El numero menor de los numeros es %i \n",bajo);
	
	
	return 0;
}
