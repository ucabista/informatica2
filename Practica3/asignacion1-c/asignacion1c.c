#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int my_nsubstr(const char *s1, const char *s2){ 
int i,j;
int b=0; // variable de retorno 
const char *ptr1,*ptr2;

 j=strlen(s2)-strlen(s1);
	for(i=0;i<=j;i++) 
		for(ptr1=s1,ptr2=s2+i;*ptr1++==*ptr2++;)
			if(*ptr1=='\0') b++;
				ptr1=s1-strlen(s1);
	return b; 
}

int main(){
	char *cad1={"esternocleidomastoideo"};
	char *cad2={"e"};
	
	printf("Cadena 1: %s \n",cad1);
	printf("Cadena2: %s \n",cad2);
	printf("la cadena %s se encuentra %d veces en la cadena buscada \n",cad2,my_nsubstr(cad2,cad1));
	
}
