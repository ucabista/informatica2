// ejercicio 8 (Busqueda Secuencial)
// Escriba una función en C, verifique la existencia de un elemento en un arreglo

// (Busqueda Binaria o Dicotonica) (todos los elementos deben estar ordenadas en forma ascendente)
// (Busqueda Secuencial) (pueden estar desordenados los elementos)

#include <stdio.h>

int main(){
	
	int a[5]={3,2,1,4,5};
	char band = 'F'; // falso
	int i,dato;
	
	// Busqueda Secuencial
	
	dato=3;
	i=-1;
	while((band=='F')&&(i<5)){
		i++;
		if(a[i]==dato){
			band='V';
		}
		
	}
	
	if(band=='F'){ // no se encontro
		printf("El numero no existe en el arreglo");
	}else if(band=='V'){
		printf("El Numero %i existe en la posicion %i",dato,i);
	}
	
	
	
	
	return 0;
}


