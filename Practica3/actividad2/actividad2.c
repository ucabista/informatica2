#include <stdio.h>
char string1[12] ={'H','o','l','a',' ','M','u','n','d','o','\0'};
char string2[] = "Hola Mundo";
char *string3 = "Hola Mundo";
char *ap_string[] = {"Uno","Dos","Tres"};
char abc[][6] = {"Uno","Dos","Tres"};
	int main(void){
		printf("Tamaño de string1:%d\n",sizeof(string1));
		printf("Tamaño de string2:%d\n",sizeof(string2));
		printf("Tamaño de string3:%d\n",sizeof(string3));
		printf("Tamaño de ap_string:%d\n",sizeof(ap_string));
		printf("Tamaño de ABC:%d\n\n",sizeof(abc));
	}
	
	

