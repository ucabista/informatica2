#include<stdio.h>
#include<stdlib.h>
int main(){
	
	char cad1[] = "Nombre: Wilter";
	char cad2[] = " Apellido: Diaz";
	char * resultado = strcat(cad1,cad2);
	
	printf("%s",resultado);
	free(resultado);
	return 0;
	
}

char *strcat(char * str1, char * str2){
	/*para evitar fallos*/
	
	if(str1 && str2){
		
		/*Reservo memoria contando cada elemento de la cadena*/
		int str1len=0;
		
		/*cuento cadena 1*/
		for(; str1[str1len] != '\0';str1len++);
		
		int str2len = 0;
		
		/*cuento cadena 2*/
		for(; str2[str2len] != '\0';str2len++);
		
		/*reservo memoria para una nueva cadena concatenada*/
		char * str1str2 = (char *)malloc(sizeof(char)*(str1len + str2len + 1));
		
		/*copio cadena 1 a variable de retorno*/
		int i;
		for(i=0;i<str1len;i++)
			str1str2[i]=str1[i];
			
			/*copio cadena 2 a variable de retorno desde el largo de la cadena 1*/
			for(i=0;i<str2len;i++)
			str1str2[i + str1len]=str2[i];
			
			/*arreglo el ultimo caracter por que \0 */
			str1str2[str1len+str2len] = '\0';
			
			return str1str2;
		}
		
		/*si en algun caso ninguna cadena es buena, pues retorna NULL*/
		
		return NULL;
	}

