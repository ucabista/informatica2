#include<stdio.h>
#include<stdlib.h>
#include "./lista.h"

int promedio(Node *list);

int promedio(Node *list){
	
	int suma=0,n=0;
	for(;list!=NULL;list=list->next){
		suma=suma+list->value;
		n++;
	}
	
	
	
	return suma/n;	
}

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
	float prom=0;
	Node *newnodo=NULL;
    Node *lista=NULL;
    
    int i,n=0;
    // Ingresar elementos en nuestra lista de 2 en 2
	for(i=1;i<=4;i++){
		n +=2; 
	    newnodo=new_item(n); // agregar elementos a mi lista
		
		lista=add_front(lista,newnodo); // agregar liga a mi lista
	}
	
	prom = promedio(lista);
	
	//Lista con los primeros elementos
	printf("Primeros elementos de la lista \n");
	print(lista);
	printf("promedio de numeros en la lista es: %2.f \n",prom);
	
	ordenar_burbuja(lista);
	
	
		
	
	return 0;
}
