#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

// Crear en una nueva lista, la suma de lista1+lista2 RESUELTO

Node *sum(Node *list1, Node *list2); // retorna una nueva lista con la suma de list1 y list2

Node *sum(Node *list1, Node *list2){
	
	Node *lista3=NULL;
	Node *newnodo3=NULL;
	
	newnodo3=new_item(list1->value+list2->value); // agregar valores de nodos
	lista3=add_front(lista3,newnodo3);
	 
	 return lista3;
}

int main(){
	
	Node *newnodo=NULL;
    Node *lista1=NULL;
    Node *lista2=NULL;
    
    Node *NuevaLista=NULL;
    
    newnodo=new_item(1); //paso el valor de 1
    lista1=add_front(lista1,newnodo);
    newnodo=new_item(2); // paso el valor de 2
    lista2=add_front(lista2,newnodo);
    
    NuevaLista=(sum(lista1,lista2));
    
    printf("imprimir suma de lista1+lista2 en Lista3 \n \n");
    print(NuevaLista);
	
	return 0;
}
