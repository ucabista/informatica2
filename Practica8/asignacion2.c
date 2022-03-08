#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Estructura arbol*/
typedef struct node{
	int codigoI;
	char autor[20],cat;
	struct node *izq, *der;
}arbol;

//Estructura de los codigos en listas
typedef struct nodo2{
	int codigo;
	struct nodo2 *next;
} interno;


typedef struct nodo{
	char categ;
	interno *codigo;
	struct nodo *next;
} node;

void imprime_codigo(interno *lista){
	printf("-->");
	for (;lista!=NULL; lista=lista->next)
		printf("%i -->",lista->codigo);
	printf("NULL\n");
}

void imprime(node *listaa){
	for (;listaa!=NULL; listaa=listaa->next){
		printf("%c-->",listaa->categ);
		printf("Codigos:");
		imprime_codigo(listaa->codigo);
	}		
	printf("\n \n");
}
// insertar elementos
int inserta(arbol **A, int codigoI, char autor[], char categoria){
	if (*A==NULL){
		*A=(arbol*)malloc(sizeof(arbol));
		(*A)->codigoI=codigoI;
		strcpy((*A)->autor, autor);
		(*A)->cat=categoria;
		(*A)->izq=(*A)->der=NULL;
		return 1;
	}
	if (codigoI==(*A)->codigoI)
		return 0;
	if (codigoI<(*A)->codigoI)
		return inserta(&((*A)->izq), codigoI, autor, categoria);
	else
		return inserta(&((*A)->der), codigoI, autor, categoria);
}

//Creamos nuevo nodo de codigo, cada vez que se llama a la funcion
interno* new_codigoI(int codigoI){
	interno *L = (interno*)malloc(sizeof(interno));
	
	if (L==NULL){
		fprintf(stderr,"error en malloc\n");
		exit(1);
	}
	L->codigo=codigoI;
	L->next=NULL;
	
	return L; 
}

//Agregamos un nuevo codigo al nodo
interno* add_codigoI(interno *lista, interno *plus){
	if (lista==NULL)
		return plus;
	
	interno *c;
	for (c=lista; c->next!=NULL; c=c->next);
	c->next=plus;
	
	return lista;
}
//Crea un nuevo nodo de la lista para las categorias
node* nueva_categ(char cat){
	node *L = (node*)malloc(sizeof(node));
		
	if (L==NULL){
		fprintf(stderr,"error en malloc\n");
		exit(1);
	}
	L->categ=cat;
	L->codigo=NULL;
	L->next=NULL;
	
	return L;
}

// Agregar nuevo nodo a la lista
node* add_end(node *lista, node *add){
	node *p;
	
	if (lista==NULL)
		return add;
		
	for (p=lista; p->next!=NULL; p=p->next);
		p->next=add;

	return lista;
}
//Buscar un elemento en la lista
node *buscar(node *listap, char cat){
	for(;listap!=NULL;listap=listap->next)
		if(cat == listap->categ)
			return listap;
			
	return NULL; 
}

// Generamos la lista ordenada a partir del arbol de busqueda
void generar_listaa(arbol *A, node *lista){
	if (A==NULL)
		return;
	
	lista = buscar(lista, A->cat);
	lista->codigo=add_codigoI(lista->codigo, new_codigoI(A->codigoI));

	generar_listaa(A->izq, lista);
	generar_listaa(A->der, lista);
}

/*Contar codigos por cada nodo*/
int conteo(interno *lista){
	int contador;
	
	for (contador=0; lista!=NULL; lista=lista->next, contador++);
	
	return contador;
}

int main(){
	int i,opc;
	const char ABCD[]={'A','B','C','D'};
	arbol *arbol=NULL;
	node *listaa=NULL;
	
	
	inserta(&arbol, 1, "Wilter", 'A');
	inserta(&arbol, 2, "esternocleidomastoideo", 'A');
	inserta(&arbol, 3, "Abuela", 'B');
	inserta(&arbol, 4, "Programacion", 'B');
	inserta(&arbol, 5, "Motivacion", 'C');
	inserta(&arbol, 6, "Juegos", 'D');
	inserta(&arbol, 7, "Peliculas", 'D');
	
	node *p =listaa;

	for (i=1; i<=4; i++){
		listaa = add_end(listaa,nueva_categ(ABCD[i-1]));
	}
		
		
	generar_listaa(arbol,listaa);
	imprime(listaa);
	
	
	printf("Ingrese un numero de categoria por favor: \n");
	printf("[1]:A \n");
	printf("[2]:B \n");
	printf("[3]:C \n");
	printf("[4]:D \n");
	
	scanf("%i", &opc);
	for (; listaa->categ!=ABCD[opc-1]; i++, listaa=listaa->next);
	printf("Numero de codigo dentro del nodo %c: %i \n", ABCD[opc-1], conteo(listaa->codigo));

	return 0;
}

