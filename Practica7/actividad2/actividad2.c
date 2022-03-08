
/*
 * UCAB - Guayana
 * Algoritmos y Programacion II
 *
 * Practica 7 - Recursion
 * Alumnos 
 * Wilter Diaz 27.922.999
 * Jesús Rodríguez 27.731.947
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 40

// Se definen las estructuras para el laberinto

char laberinto[MAX_FILAS][MAX_COLUMNAS];
int  filas,columnas;
int aux1[8][8];

// Carga el laberinto desde un archivo
// Se define un laberinto cerrado de tamaño maximo MAX_FILAS x MAX_COLUMNAS donde
// las paredes se componen por cualquier caracter y los pasillos por blancos

int cargar_laberinto(char *name){
	int i=0,j=0;
	FILE *arch;
	char c;

	if((arch = fopen(name, "r")) == NULL){
		fprintf(stderr, "Error: No se pudo abrir %s \n",name);
		return 0;
	}
	while((c=getc(arch))!= EOF)
		if(c=='\n'){
			columnas=(columnas>j?columnas:j);
			i++;
			j=0;
		}
		else{
			if(i<MAX_FILAS && j<MAX_COLUMNAS)
				laberinto[i][j++]=c;
			else{
				fprintf(stderr,"Error: Tamaño del laberinto\n");
				return 0;
			}
		}
	filas=i;
	fclose(arch);
	return 1;
}

// Se imprime el laberinto en pantalla con o sin escalas

void imprime_laberinto(int escalas){
	int i,j;

	if(escalas){
		printf("   ");
		for(j=0;j<columnas;j++)
			printf ("%c",!(j%10)?(char)(j/10+'0'):' ');
		printf("\n   ");
		for(j=0;j<columnas;j++)
			printf ("%d",j%10);
		printf("\n\n");
	}
	for(i=0;i<filas;i++){
		if(escalas)
			printf("%2d ",i);
		for(j=0;j<columnas;j++)
			printf("%c",laberinto[i][j]);
		printf("\n");
	}
	printf("\n");
}

// Pregunta por la posicion de titulo en el laberito, verifica la posicion en
// el mismo, finalmente la marca con Logo y retorna la posicion: fila, columna

void posicion(char logo,char *titulo,int *f,int*c){
	do{
		printf("Posicion del %s (F,C):",titulo);
		scanf("%d,%d",f,c);
	}while(*f<0 || *f>=filas || *c<0 || *c>=columnas  || laberinto[*f][*c]!=' ');
	laberinto[*f][*c]=logo;
}

// buscar: Funcion que debe modificar para recorrer el laberinto desde la
//         posicion (f,c) buscando el caracter 'Q' y marcando con 'r' el
//         camino que lleva a Q en caso de exito

int buscar(int f,int c){
	if(laberinto[f][c]=='Q')
	return 1;
	


if((laberinto[f][c])!=' ' && laberinto[f][c] !='R' || aux1[f][c]){
	
return 0;	
}


aux1[f][c] = 1;

if(f!=0){
	if(buscar(f-1,c)){
		laberinto[f][c]='r';
		return 1;
	}
}

if(f !=filas -1 ){
	if(buscar(f+1,c)){
		laberinto[f][c]='r';
		return 1;
	}
}


	if(f!= filas -1){
		if(buscar(f+1,c)){
			laberinto[f][c]='r';
			return 1;
		}
	}
	
	if(c!=0){
		if(buscar(f,c-1)){
			laberinto[f][c]='r';
			return 1;
		}
	}
	
	if(c!=columnas -1){
		if(buscar(f,c+1)){
			laberinto[f][c]='r';
			return 1;
		}
	}
	
	return 0;
}

int main(int argc, char *argv[]){
	int f,c;

	if(argc < 2){
		fprintf(stderr,"uso %s archivo\n",argv[0]);
		return 1;
	}
	if(cargar_laberinto(argv[1])){
		imprime_laberinto(1);
		posicion('Q',"Queso",&f,&c);
		imprime_laberinto(1);
		posicion('R',"Raton",&f,&c);
		imprime_laberinto(0);
		if(buscar(f,c)){
			laberinto[f][c]='R';
			imprime_laberinto(0);
		}
		else
			printf("\nEl raton no encontro el queso\n");
	}
	return EXIT_SUCCESS;
}
