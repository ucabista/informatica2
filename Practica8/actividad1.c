#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

typedef struct nodo{
int elemento;
struct nodo *izq,*der;
} nodo_t,nodo_t2;

// insertar elementos en el arbol
int inserta(nodo_t **arbolbp,int elemento){
	
	if(*arbolbp==NULL){
		*arbolbp=(nodo_t *)malloc(sizeof(nodo_t));
		(*arbolbp)->elemento=elemento;
		(*arbolbp)->izq=(*arbolbp)->der=NULL;
		return 1;
	}
	
	if(elemento==(*arbolbp)->elemento)
	return 0;

	if(elemento<(*arbolbp)->elemento)
	return inserta(&((*arbolbp)->izq),elemento);
	else
	return inserta(&((*arbolbp)->der),elemento);
}
// busca el menor elemento
int menor(nodo_t *arbolbp, int *elemento){
if(arbolbp==NULL)
return 0;
while(arbolbp->izq != NULL)
 arbolbp=arbolbp->izq;
*elemento = arbolbp->elemento;
return 1;
}
int izq(nodo_t *arbolbp){
int cont=0;
if(arbolbp==NULL)
return 0;
while(arbolbp->izq != NULL){
 
cont=cont+1;
arbolbp=arbolbp->izq;}
return cont;
}

int der(nodo_t *arbolbp){
int cont=0;
if(arbolbp==NULL)
return 0;
while(arbolbp->der != NULL){
cont=cont+1;
arbolbp=arbolbp->der;}

return cont;
}

//busca el mayor elemento
 int mayor(nodo_t *arbolbp, int *elemento){
if(arbolbp==NULL)
return 0;
while(arbolbp->der != NULL)
arbolbp=arbolbp->der;
*elemento = arbolbp->elemento;
return 1;
}

void imprime(nodo_t *arbolbp,int nivel){
int i;

if(arbolbp==NULL)
return;
imprime(arbolbp->der,nivel+1);
for(i=0;i<nivel;i++)
printf(" ");
printf("%d\n",arbolbp->elemento);
imprime(arbolbp->izq,nivel+1);
}


int izqq(nodo_t *arbolbp){
int cont=0;
if(arbolbp==NULL)
return 0;
while(arbolbp->izq != NULL){
 
cont=cont+1;
arbolbp=arbolbp->izq;}
return cont;
}

int derr(nodo_t *arbolbp){
int cont=0;
if(arbolbp==NULL)
return 0;
while(arbolbp->der != NULL){
cont=cont+1;
arbolbp=arbolbp->der;}

return cont;
}


int main(void){
	
nodo_t *arbol=NULL;
nodo_t2 *arbol2=NULL;

int e,i,aleatorio, P, U;
srand(time(NULL)); // generar numeros aleatorios

for(i=0;i<100;i++){
	
 aleatorio = P+(int)(((U-P+1.0)*rand())/(RAND_MAX+1.0));
 inserta(&arbol,aleatorio); 
 
 if(aleatorio % 2>0){ // impar
 	inserta(&arbol2,aleatorio);
 }         
	
} 

imprime(arbol,1);
printf("arbol 2 \n\n "); 
imprime(arbol2,1);

if(menor(arbol,&e))
printf("\nmenor:%d \n",e);

if(mayor(arbol,&e))
printf("\nmayor:%d \n",e);


}
