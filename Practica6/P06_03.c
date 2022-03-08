/*
 * UCAB Guayana - Algoritmos y programacion II
 * Practica 06
 *
 * P0_603.c - Implementacion de busqueda por acceso directo
 *            en un archivo - raf
 *
 */

#include <stdio.h>

//Estructura para guardar datos del archivo
struct{
   int numero;
   char enTexto[60];
   float magic[2];
} reg;

int main(int argc, char *argv[]){
   FILE *fd;
   long pos;
   int registro = 12345;

   //intenta abrir archivo datos.raf en modo lectura
   if((fd=fopen("datos.raf","r")) == NULL){
      fprintf(stderr,"Error: al abrir el archivo de entrada\n");
      return 1;
   }
	
	
   //Se va a posicion en bytes donde esta el registro en el archivo
   pos = sizeof(reg) * (long)registro;
   //Accede a posicion con fseek
   if(fseek(fd,pos,SEEK_SET)==0){
	  //Lee los datos 
      fread((void *)&reg, sizeof(reg), 1, fd);
	  //Imprime los datos 
      printf("Numero:%5d\nEnTexto:[%s]\nMagic1:%.2f\nMagic2:%.2f\n",
             reg.numero, reg.enTexto, reg.magic[0], reg.magic[1]);
   }
	
   //Cierra archivo	 
   fclose(fd);
   return 0;
}