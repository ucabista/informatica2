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
		
		add_end(lista,lista2);
		
		lista=Re_verse(lista);
		printf("Lista invertida en su version Recursiva: \n\n");	
		print(lista);
	
	return 0;
}
