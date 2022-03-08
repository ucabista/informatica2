#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
char name[20];
int value;
struct node *next;
} Node;



/*
Primera Funcion
* New_item: Crea un nuevo elemento a partir
* del nombre y un valor
*/
Node *new_item(char *name, int value){
Node *newp;
if((newp=(Node *)malloc(sizeof(Node)))==NULL){
fprintf(stderr,
 "new_item: error en malloc\n");
exit(1);
}
strcpy(newp->name,name);
newp->value = value;
newp->next=NULL;
return newp;
}

/*
* add_front: añade newp al frente de listp
*/
Node *add_front(Node *listp, Node *newp){
newp->next=listp;
return newp;
}
/*
* add_end añade newp al final de la listp
*/
Node *add_end(Node *listp, Node *newp){
Node *p;
if(listp==NULL)
return newp;
for(p=listp;p->next!=NULL;p=p->next);
p->next = newp;
return listp;
}
/*
* print: muestra los elementos en listp
*/
void print(Node *listp){
printf("-->");
for(;listp!=NULL;listp=listp->next)
printf("%s:%d-->",listp->name,listp->value);
printf("NULL\n");
}

/* Reverse de forma iterativa */
Node *reverse(Node *listp){
Node *next, *p=NULL;

while(listp){

next=listp->next;
listp->next=p;
p=listp;
listp=next;
// Imprimir lista
}

return p;

}

/*Funcion copiar listas*/
Node *copy(Node *listp){

Node *apuntador=(Node*)malloc(sizeof(Node));
//listp es la lista que se va a copiar
apuntador=listp;

// imprimir la copia
print(listp);

return apuntador;

}


/*Lista invertida en su version recursiva*/
	Node *Re_verse(Node*listp){
		Node *cola;
		
		if(listp == NULL)
		return NULL;
		cola=listp->next;
		listp->next=NULL;
		return add_end(Re_verse(cola),listp); // primer elemento
		
	}




