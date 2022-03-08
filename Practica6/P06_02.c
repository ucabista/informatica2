/*
 * UCAB Guayana - Algoritmos y programacion II
 * Practica 06
 *
 * P6_02.c - Procesamiento secuencial del archivo de datos
 *           y construcion de un archivo acceso directo - raf
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura para guardar datos del archivo datos.dat
struct{
   int numero;
   char enTexto[60];
   float magic[2];
} reg;

int main(int argc, char *argv[]){
   FILE *fd1, *fd2;
   char buffer[100];
   int r=0, i=0, f;

   //Intenta abrir datos.dat en modo lectura, si no existe da error
   if((fd1=fopen("datos.dat","r")) == NULL){
      fprintf(stderr,"Error: al abrir el archivo de origen\n");
      return 1;
   }
	
   //abre datos.raf en modo escritura, si no existe lo crea
   if((fd2=fopen("datos.raf","w")) == NULL){
      fprintf(stderr,"Error: al abrir el archivo de destino\n");
      return 1;
   }

  //Mientras haya lineas en el archivo
  while(fgets(buffer,99,fd1)!=NULL){

	  //Guarda la cadena desde el inicio de linea antes del primer ";" en buffer
      for(f=0; buffer[f] != '\0' && buffer[f] != ';'; f++);
      buffer[f] = '\0';
	  
	  //Transforma buffer a entero y lo guarda en reg, en su variable numero
      reg.numero = atoi(buffer);
	
      //Guarda la cadena desde despues del primer ";" hasta antes del segundo ";" en buffer
      for(i=++f; buffer[f] != '\0' && buffer[f] != ';'; f++);
      buffer[f] = '\0';

      //Copia buffer en reg, en su variable enTexto
      strcpy(reg.enTexto, &buffer[i]);

	  //Guarda la cadena desde despues del segundo ";" hasta antes del tercer ";" en buffer
      for(i=++f; buffer[f] != '\0' && buffer[f] != ';'; f++);
      buffer[f] = '\0';
	   

	  //Transforma buffer en flotante y lo guarda en reg.magic[0]
      reg.magic[0] = (float)atof(&buffer[i]);


	  //Para avanzar buffer al siguiente espacio
      i=++f;
	   

	  //Transforma buffer en flotante y lo guarda en reg.magic[1]
      reg.magic[1] = (float)atof(&buffer[i]);
	   


	  //Se gyarda el rgistro en fatos.raf
      fwrite((void *)&reg,sizeof(reg),1,fd2);
	  //Si numero es 12345
      if(reg.numero==12345)
		  //Se imprimen datos
         printf("Numero:%5d\nEnTexto:[%s]\nMagic1:%.2f\nMagic2:%.2f\n",
         reg.numero, reg.enTexto, reg.magic[0], reg.magic[1]);
      r++;
   }

   //Cerrar archivos
   fclose(fd2);
   fclose(fd1);
   printf("%d registros procesados\n",r);
   return 0;
}