#include<stdio.h>
#include<stdlib.h>
#include "lista.h"
#include<string.h>


int main(){
	
        Node *newnodo=NULL;
        Node *lista=NULL;
        
        Node *newnodo2=NULL;
        Node *lista2=NULL;
        
        
  		
		newnodo=new_item("Wilter",20);
		lista=add_front(lista,newnodo);
		
		newnodo2=new_item("Maria",20);
		lista2=add_front(lista2,newnodo2);
		
		printf("Agregar Nuevo item en la lista e imprimir\n\n");
		print(lista);
		
		// enviar lista a copy
		printf("Copia de lista 1 en listp: \n\n");
		copy(lista);
		
			
		add_end(lista,lista2);
		printf("Agregar newp al final de la lista \n\n");
		print(lista);
		
		printf("Lista de forma invertida: \n\n ");
		lista=reverse(lista);
		print(lista);
		
		

        return 0;
}
