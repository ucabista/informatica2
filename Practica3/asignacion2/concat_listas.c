#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

concatenar(Node *listp1,Node *listp2); // Prototipo

int main(){

Node    *newnodo=NULL;
        Node *lista=NULL;
        
        Node *newnodo2=NULL;
        Node *lista2=NULL;
        
        newnodo=new_item("Wilter",123);
		lista=add_front(lista,newnodo);
		
		newnodo2=new_item("Diaz",456);
		lista2=add_front(lista2,newnodo2);
		

concatenar(lista,lista2);

}
concatenar(Node *listp1,Node *listp2)
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
