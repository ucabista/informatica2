#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_strrev(char s[]){
int i,leng = strlen(s);
char aux;

	for(i=0;i<leng/2;i++){ //partimos e invertimos
		aux=s[i];
		s[i]=s[leng-i-1];
		s[leng-i-1]=aux; // hacemos el cambio
	}
}

int main(){
	char cad1[]="Wilter";
	
	printf("Cadena original: %s \n",cad1);
	my_strrev(cad1);
	printf("Cadena invertida: %s",cad1);
	
}
