/*¿Qué problema tiene la siguiente función? Reescriba el código de la
función para arreglarlo, sin cambiar las premisas de uso.
char* WordInput(){
char word[20];
 printf ("Type a word: ");
scanf ("%s", word);
return word;
}
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* WordInput(char *word){
	int i=0;
	*word = calloc(20,sizeof(char));
	
	 	printf("Type a word: ");
		scanf("%s", word);
			
	return word;
	}

int main(){
	char word[20];

	strcpy(word,WordInput(word));
	printf("%s",word);
	
	return 0;
}
