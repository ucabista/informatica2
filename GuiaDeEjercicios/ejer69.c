#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
int valor;
struct node *next;
} Node;

// add_front: añade newp al frente de listp

Node *add_front(Node *listp, Node *newp){
newp->next=listp;
return newp;
}

//Agrego valores a mi lista 
Node *new_item(int valor){
Node *newp;
if((newp=(Node *)malloc(sizeof(Node)))==NULL){ // si esta vacio 
fprintf(stderr,"new_item: error en malloc\n");
exit(1);
}

newp->valor = valor;
newp->next=NULL;
return newp;
}



//imprimir datos de lista
void print(Node *listp){
for(;listp!=NULL;listp=listp->next)
printf("%d-->",listp->valor);
printf("NULL\n");
}

int cuadradox(int valor){
	
	return valor*valor;
}

void mi_funcion(Node *listp,int (*funcion)(int, int)){
	
	Node *newnodo=NULL;
    Node *lista=NULL;
    int n=0;
	
	for(;listp!=NULL;listp=listp->next){
		n +=2;
		int resultado=cuadradox(n);
		newnodo=new_item(resultado); // agregar elementos a mi lista
		lista=add_front(lista,newnodo); // agregar liga a mi lista
	}
	printf("Resultado: CuadradoX \n");
	print(lista);
	
	
}


int main(){
	
	Node *newnodo=NULL;
    Node *lista=NULL;
    int i,n=0;
    // Ingresar elementos en nuestra lista de 2 en 2
	for(i=1;i<=4;i++){
		n +=2; 
	    newnodo=new_item(n); // agregar elementos a mi lista
		
		lista=add_front(lista,newnodo); // agregar liga a mi lista
	}
	//Lista con los primeros elementos
	printf("Primeros elementos de la lista \n");
	print(lista);
	
	mi_funcion(lista,cuadradox);
				
	return 0;
}
