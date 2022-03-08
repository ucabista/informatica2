/*
 * UCAB Guayana - Algoritmos y programacion II
 * Practica 06
 *
 * P06_01.c - Construccion de un archivo de datos
 *
 */

#include <stdio.h>
#include <string.h>

//Arreglos de cadenas que nos permitiran construir los nombres

//Numeros del 0 al 15
char *t1[] = {"cero", "uno ", "dos ", "tres ", "cuatro ", "cinco ", "seis ", "siete ",
              "ocho ", "nueve ", "diez ", "once ", "doce ", "trece ", "catorce ", "quince "};

//Decenas del 20 al 90 y el numero 100
char *t2[] = {"veinte ", "treinta ", "cuarenta ", "cincuenta ", "sesenta ", "setenta ",
              "ochenta ", "noventa ", "cien "};

//Decenas del 20 al 90 para ser combinadas con unidades
char *t3[] = {"dieci", "veinti", "treinta y ", "cuarenta y ", "cincuenta y ", "sesenta y ",
              "setenta y ", "ochenta y ", "noventa y "};

//centenas de 100 al 900 y el numero 1000
char *t4[] = {"ciento ", "doscientos ", "trescientos ", "cuatrocientos ", "quinientos ",
              "seiscientos ", "setecientos ", "ochocientos ", "novecientos " , "un mil "};

//Funcion para retornar el nombre de un numero dado, recibe la cadena de destino, el numero 
//y flag para las cadenas especiales
char *num2text(int numero, char* buffer, int flag){
   char temp[100];

	//Cadenas especiales
   if(flag == 1)
      if(numero == 0)
         return strcpy(buffer, " ");
      else if(numero == 1)
         return strcpy(buffer, "un ");
	
	
	//Concatena buffer con su equivalente en t1
   if(numero <= 15)
      return strcpy(buffer, t1[numero]);
	
	//Numeros divisibles entre 10 y menores o iguales a 100
   if(numero <= 100 && numero%10 == 0)
	   //Contatena buffer con su equivalente en t2
      return strcpy(buffer, t2[numero/10-2]);
	
	//Numero menor a 100 no divisible entre 10
   if(numero < 100)
	   //Se concatena a buffer t3 y el resultado de nueva llamada recursiva con el resto del numero entre 10
      return strcat(strcpy(buffer, t3[numero/10-1]), num2text(numero%10, temp, flag));
	
	//numero menor o igual a 1000 divisible entre 100
   if(numero <= 1000 && numero%100 == 0)
	   //Se concatena a buufer su equivalente en t4
      return strcpy(buffer, t4[numero/100-1]);
	
	//Numero menor a mil no divisible entre 100
   if(numero < 1000)
	   //Se concatena a buffer el equivalente de la centena en t4 + llamada recursiva con numero mod 100 
      return strcat(strcpy(buffer, t4[numero/100-1]), num2text(numero%100, temp, flag));
	//Numero menor a un millon divisibles entre 1000
   if(numero < 1000000 && numero%1000 == 0)
	   //LLamo a la funcion de forma recursiva y al resultado le concateno la cadena "mil"
      return strcat(num2text(numero/1000, buffer, 1), "mil ");
	//Numero menor a un millon no divisible entre 1000
   if(numero < 1000000)
	   //Dos llamadas recursivas a la funcion, una con la division entera entre 1000 mas la cadena "mil" y otra con el numero mod 1000
      return strcat(strcat(num2text(numero/1000, buffer, 1), "mil "), num2text(numero%1000, temp, 0));
	//Numero es un millon
   if(numero == 1000000)
      return strcpy(buffer, "un millon ");
	//Numero menor a 1000000000
   if(numero < 1000000000)
	   //Dos llamadas recursivas a la funcion, una con la division entera entre 1000000 mas la cadena "mil" y otra con el numero mod 1000000
      return strcat(strcat(num2text(numero/1000000, buffer, 1), "millones "), num2text(numero%1000000, temp, 1));
	//Numero invalido
   return strcpy(buffer, " *** ERROR *** \n");
}

//Funcion para poner la primera letra de la cadena final en mayusculas
char *numeroAtexto(int numero, char *dest){
   dest = num2text(numero, dest, 0);
	
	//Se capitaliza primera letra
   *dest = *dest + 'A' - 'a';
   return dest;
}

int main(int argc, char *argv[]){
    FILE *fd;
    int i=15;
    char buffer[100];
	
	//Abree archivo datos.dat
    if((fd=fopen("datos.dat","w")) == NULL){
       fprintf(stderr,"Error: al abrir el archivo\n");
       return 1;
    }
	
	//Se llena archivo datos.dat
    for(i=0; i<=50000; i++){
       fprintf(fd,"%d;%s;%.2f;%.2f\n", i, numeroAtexto(i, buffer), (float)i+0.5, (float)i);
    }
	//Se cierra archivo
    fclose(fd);
	
	//Se llama a la funcion para que retorne la cadena de numeros que se le dan
    printf("\n%d --> %s\n",321451761,numeroAtexto(321451761, buffer));
    printf("\n%d --> %s\n",987654321,numeroAtexto(987654321, buffer));
    printf("\n%d --> %s\n",500550555,numeroAtexto(500550555, buffer));
    printf("\n%d --> %s\n",999999999,numeroAtexto(999999999, buffer));
    return 0;
 }