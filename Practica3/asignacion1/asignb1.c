#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_strdump(const char *f){ 
char *d;
 
	d=(char *)malloc(my_strlen(f)+1); 
	my_strcpy(d,f);
	return d;
}

int main(){
	char cad1[]="wilter";
	char cad2[]="diaz";
	char cad3[]="t";
	
	printf("cadena 1: %s \n",cad1);
	printf("cadena 2: %s\n",cad2);
	printf("cadena 3: %s\n",cad3);
	
	printf("La cadena %s mide %d de longitud \n", cad1, my_strlen(cad1)); 		
	my_strcpy(cad1,cad2);
	printf("Funcion de my_strcpy Copia Cadena 1 a cadena2: %s \n",cad2);
	my_strcat(cad1,cad2);
	printf("Funcion de my_strcat Cadena 1 con cadena2: %s \n",cad1);
	printf("Funcion de my_strdump Cadena 1 concatenada: %s \n", my_strdump(cad1));
	printf("Funcion de my_substr cadena 3 buscando en cadena1: %d \n", my_substr(cad3,cad1));
}

int my_strlen(const char *s){  // Longitud de cadena de caracteres
register const char *p = s;
 
	while(*p) //*p!='\0'
		p++; 
	return p-s; 
}

void my_strcpy(char *d, const char *f){
	while(*d++ = *f++); 
}

void my_strcat(char *d, const char *f){ 
	my_strcpy(d+my_strlen(d),f); 
}

int my_substr(const char *s1, const char *s2){ 
int i,v; 
const char *p1,*p2; v=my_strlen(s2)-my_strlen(s1);

	for(i=0;i<=v;i++) 
		for(p1=s1,p2=s2+i;*p1++==*p2++;)
			if(*p1=='\0') return i;
	return -1; 
}
