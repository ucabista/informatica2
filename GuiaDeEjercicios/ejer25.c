/*Que problema tiene el siguiente algoritmo reescribalo para arreglarlo*/

#include<stdio.h>
#include<string.h>

char* WordInput(); // prototipo
int main(){
	
	char palabra[20];
	
	strcpy(palabra,WordInput(palabra)); // enviar parametros y asignagnacion
	
	printf("%s ",palabra);
	
	return 0;
}

char* WordInput(){
	char word[20];
	printf ("Type a word: ");
	scanf("%s", &word); // Lo que está mal es que falta el & simbolo para guardar datos en la direccion de memoria de la variable
	return word;
	}
