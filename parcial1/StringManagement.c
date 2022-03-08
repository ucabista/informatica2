#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadenita[20];

char *eliminar(char *cadena, char *subcadena) {

    char *start = strstr(cadena, subcadena);
    char *end = start + strlen(subcadena);
    strcpy(start, end);
	
	return cadena;
} //Fin eliminar

char *reemplazar(char *cadena, char *subcadena, char *subcadena1) {
	cadenita auxchain="";
	
	strcpy(auxchain,cadena); //Copio la cadena original en una auxiliar
	
	char *start = strstr(cadena, subcadena); //Posicion de "subcadena" en "cadena"
    char *end = start + strlen(subcadena); //Final de "subcadena" en "cadena"

	strcpy(auxchain, end);	//trunco la cadena auxiliar hasta donde termina "subcadena", esto hace que subcadena se borre
	strcpy(start,""); //trunco la cadena a partir de la posicion donde aparece "subcadena"
	
	//Uno las cadenas resultantes con "subcadena1"
	strcat(subcadena1,auxchain); //subcadena1 = subcadena1 + auxchain
	strcat(cadena,subcadena1); //cadena = cadena + subcadena1
	return cadena;
} //Fin reemplazar

int main() {
	short s;
	cadenita chain, subchain,newchain;
	
	printf("Introduzca una cadena de texto: ");
	gets(chain);
	
	do {
		printf("Que accion desea realizar?\n");
		printf("[1]: Borrar subcadena.\n");
		printf("[2]: Reemplazar subcadena.\n");
		printf("[0]: Salir.\n");
		scanf("%i",&s);
		
		switch (s){
		case 1: {
			printf("Inserte cadena a eliminar: ");
			scanf("%s",&subchain);
			eliminar(chain,subchain);
			break;
		}
		case 2: {
			printf("Inserte cadena a reemplazar: ");
			scanf("%s",&subchain);
			printf("Inserte nueva subcadena: ");
			scanf("%s",&newchain);
			reemplazar(chain,subchain, newchain);
			break;
		}
		case 0: break;
		default: printf("No valido.\n");
		} //Fin casos
		
			printf("Cadena resultante: %s\n\n", chain);
			
	} while (s!=0);
	printf("\nSe ha salido.");
	
	return 0;
} //Fin main
