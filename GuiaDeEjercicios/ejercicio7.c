/*Escriba una función en C, que dados un arreglo enteros retorne el
mayor, menor y el promedio.*/

#include <stdio.h>

int main(){
	
int arreglo[5]={0,4,2,3,1};
int menor=999,mayor=0,aux=0,i;
float prom,sumatoria=0;

for (i=0;i<5;i++){
	
	sumatoria += arreglo[i];

if(arreglo[i]>mayor){
	
	mayor=arreglo[i];

}else if(arreglo[i]<menor){
	
	menor=arreglo[i];
}	
	
}

prom = sumatoria/5;

printf("El mayor de todos es %i \n",mayor);
printf("El menor de todos es %i \n",menor);
printf("El promedio de todos es %2.f \n",prom);

	
	return 0;
}
