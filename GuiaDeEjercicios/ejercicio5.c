/*Dada una lista de elementos y las operaciones: primero, cola, insertar
un elemento por el frente e insertar un al final: Escriba los algoritmos en
pseudo código, para:
a.- Calcular la longitud de la lista //lista
b.-Verificar si dos listas son iguales //listo
c.- Concatenar dos listas //listo
d.-Buscar un elemento de forma recursiva. //listo
e.- Ordenar la Lista la lista de forma recursiva. 
f.- Voltear (invertir) la lista de forma recursiva. //listo
*/

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"



int tam_lista(Node *head){
	
	Node *p=NULL;
		
	int total=0;
	
	if(head != NULL){
		for(;head!=NULL;head=head->next)
		total++;
	}else{
		printf("lista vacia \n\n");
	}
		
	return total;
}

// 	COMPARAR LISTAS
int comparar_lista(Node *a,Node *b)
{
	while (a != NULL && b != NULL)
	{
		if (a->value != b->value)
			return 0;
			
		a = a->next;
		b = b->next;
	}

	return (a == NULL && b == NULL);
}


 void concatenar(Node *listp1,Node *listp2)
{
	Node *lista_concat=NULL; // nodo donde estará la concatenacion
	

	
	if(listp1 != NULL && listp2 != NULL){
		lista_concat=listp1;
		
		while(lista_concat->next!=NULL)
			lista_concat=lista_concat->next;
			lista_concat->next = listp2;
			listp2 = NULL;
			print(lista_concat);
		}
}


int search(Node *head, int x)
{
	int key=0;
    // caso base
    if (head == NULL)
        return key=0;
     
    
    if(head->value == x)
        return key=1;
 
    
    return search(head->next, x);
}

// ordenar pero no de forma recursiva
int ordenar_burbuja(Node *listp){
	Node *p=NULL;
	Node *q=NULL;
	char aux;
	printf("Ordenar Lista de menor a mayor");
	if(listp!=NULL){
		p=listp;
		while(p->next != NULL){
			q=p->next;
			while(q!=NULL){
				if(q->value<p->value)
				{
					aux=p->value;
					p->value=q->value;
					q->value = aux;
				}
				q=q->next;
			}
			p=p->next;
		}
	}else{
		printf("no hay elementos");
	}
	print(listp);
}




int main(){
	
	int ver=0;
	Node *newnodo=NULL;
    Node *lista=NULL;
    Node *lista2=NULL;
    Node *newnodo2=NULL;
    int i;
    for(i=1;i<=5;i++){
	    newnodo=new_item(i); // agregar elementos a mi lista
		lista=add_front(lista,newnodo); // agregar next a mi lista
	}
	int n=0;
	for(i=1;i<=5;i++){
		// n=n+2; si queremos colocar values diferentes y pasamos n como parametro
	    newnodo2=new_item(i); // agregar elementos a mi lista
		lista2=add_front(lista2,newnodo2); // agregar next a mi lista
	}
	printf("lista:1 \n");
	print(lista);
	printf("lista:2 \n");
	print(lista2);
	
	int tamano=0;
	
	// tamaño de nuestra lista
	tamano=tam_lista(lista2);
	printf("el tamano de nuestra lista1 es: %i \n\n",tamano);
	// Comparar nuestras listas
	if(comparar_lista(lista,lista2))
		printf("las listas son iguales: \n\n");
	else
	printf("las listas NO son iguales: \n\n");
	
	// Nuevas listas : : : 
	
	Node *newnodo3=NULL;
    Node *lista3=NULL;
        
    Node *newnodo4=NULL;
    Node *lista4=NULL;
        
    newnodo3=new_item(123);
	lista3=add_front(lista3,newnodo3);
		
	newnodo4=new_item(456);
	lista4=add_front(lista4,newnodo4);
	
	printf("Lista3 y Lista4 Concatenadas: \n\n");
	concatenar(lista3,lista4);
	
	int encontrado=0;
	printf("se esta buscando el elemento 1 dentro de la lista \n\n");
	encontrado=search(lista, 1);

	if (encontrado==1){
		printf("Elemento Encontrado de forma recursiva \n\n");
	}else{
	printf("Elemento No Encontrado \n\n");	
	}
	
	lista=Re_verse(lista);
		printf("Lista1 invertida en su version Recursiva: \n\n");	
		print(lista);
		
		
	ordenar_burbuja(lista); // ordenar pero no de forma recursiva
		
		
	
	
	return 0;
}
