#include <stdio.h>
#include <string.h>
void main()
{
    char Cmd[] = "mi mama me mima";
    char removed[] = "ma";

	printf("%s\n",Cmd); //Imprime cadena original
	
    while (strstr(Cmd,removed)!=NULL) { //Ciclo para borrar cada coincidencia de la subcadena
    
    	/* Coloca un puntero al inicio de la subcadena a borrar*/
    	char *start = strstr(Cmd, removed);

   		 /* Coloca un puntero al final de la subcadena a borrar*/
    	char *end = start + strlen(removed);

   		 /* elimina la cadena "removed" de Cmd */
    	strcpy(start, end);

	}
    printf("%s\n", Cmd); //Imprime cadena resultante
}
