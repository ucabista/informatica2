/*Se desea que usted implemente una función en C, que reciba 
una lista de enteros, 
un acumulador del tipo flotante 
y un apuntador a una
función, 
que retorna un entero y tiene como parámetro un entero,

retorne el resultado de acumular todos los elementos de la lista según
la función. Por ejemplo, dada la lista
(1, 2, 3, 4, 5)
Y la función productor(A,X)
El resultado es:
A = 120*/

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"



int acumulax(int valor){
		
	
	return valor;
}

void mi_funcion(Node *listp,float acumulador,int (*funcion)(int, int)){
	
	Node *newnodo=NULL;
    Node *lista=NULL;
    
	for(;listp!=NULL;listp=listp->next){
		
		acumulador = acumulador * acumulax(listp->value);
	
	}
			
	
	printf("El resultado: %2.f \n",acumulador);
		
	
}


int main(){
	
	Node *newnodo=NULL;
    Node *lista=NULL;
    int i;
    float acumulador=1;
    // Ingresar elementos en nuestra lista 1,2,3,4,5
	for(i=1;i<=5;i++){

	    newnodo=new_item(i); // agregar elementos a mi lista
		lista=add_front(lista,newnodo); // agregar liga a mi lista
	}
	//Lista con los primeros elementos
	printf("Primeros elementos de la lista \n");
	print(lista);
	
	mi_funcion(lista,acumulador,acumulax);
					
	return 0;
}
