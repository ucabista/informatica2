/*Dado las siguientes declaraciones en Lenguaje C.
int f0[] = { 0, 1, 2, 3, 4},
 f1[] = {10,11,12,13,14},
 f2[] = {20,21,22,23,24},
 f3[] = {30,31,32,33,34},
 f4[] = {40,41,42,43,44},
 *fp[] = {f0,f1,f2,f3,f4},
 **mp = fp;
int ma[][5]={{ 0, 1, 2, 3, 4},{10,11,12,13,14},{20,21,22,23,24},
 {30,31,32,33,34},{40,41,42,43,44}};
 
 a.- Dibuje las estructuras de datos, partiendo de mp y ma.
b.- escriba funciones en lenguaje C, que imprima por pantalla, a mp y ma.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//matriz1 imprimir
void print1(int **matriz){
	int i,j;
	
	for(i=0;i<5;i++){
 		for(j=0;j<5;j++){
 			printf("%i ",matriz[i][j]);
		 }
		 printf("\n");
	 }
	 printf("\n");
}

// matriz2 imprimir
void print2(int matriz[5][5]){
	int i,j;
	
	for(i=0;i<5;i++){
 		for(j=0;j<5;j++){
 			printf("%i ",matriz[i][j]);
		 }
		 printf("\n");
	 }
	 printf("\n");
}

int main(){	
	
int 
 f0[] = { 0, 1, 2, 3, 4},
 f1[] = {10,11,12,13,14},
 f2[] = {20,21,22,23,24},
 f3[] = {30,31,32,33,34},
 f4[] = {40,41,42,43,44},
 *fp[] = {f0,f1,f2,f3,f4},
 **mp = fp;

int ma[][5]={{ 0, 1, 2, 3, 4},{10,11,12,13,14},{20,21,22,23,24},
 {30,31,32,33,34},{40,41,42,43,44}};
 	
 	
 	
	printf("Primera matriz: \n");
 	print1(mp); // imprimir mp
 	printf("Segunda matriz: \n");
 	print2(ma); //imprimr ma
 	
 
	
	return 0;
}





