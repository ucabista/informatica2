/*
 * UCAB Guayana - Algoritmos y programacion II
 * Practica 06
 *
 * P0_603.c - Implementacion de busqueda por acceso directo
 *            en un archivo - raf
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
   int numero;
   char enTexto[60];
   float magic[2];
} reg;

int main(int argc, char *argv[]){
   FILE *fd;
   long pos;
   int opcion = -1,registro, f;
	char buffer[100];

   if((fd=fopen("datos.raf","r")) == NULL){
      fprintf(stderr,"Error: al abrir el archivo de entrada\n");
      return 1;
   }
	
	printf("Introduce el numero a buscar:\n");
    scanf("%d", &registro);
	
	while(fgets(buffer,99,fd)!=NULL){
		
     for(f=0; buffer[f] != '\0' && buffer[f] != ';'; f++);
     buffer[f] = '\0';
   
      reg.numero = atoi(buffer);

      if(reg.numero==registro) {
		  opcion = 1;
	  }
       
  
   }
    if(opcion == 1){
		while (1) {
        	printf("Opciones:\n");
        	printf("1. Busqueda\n");
    	    printf("2. Modificacion\n");
        	printf("3. Borrado\n");
    		printf("4. Salir\n");
        	scanf("%d", &opcion);
    		fread((void *)&reg, sizeof(reg), 1, fd);
        	if (opcion == 1) {
                printf("Numero:%5d\nEnTexto:[%s]\nMagic1:%.2f\nMagic2:%.2f\n",
                reg.numero, reg.enTexto, reg.magic[0], reg.magic[1]);
	
		
    	    } else if (opcion == 2) {
	    	    while (1) {
        			printf("Opciones\n");
    	    		printf("1. Modificar entero:\n");
    		    	printf("2. Modificar cadena de caracteres:\n");
        			printf("3. Modificar flotante 1\n");
    	    		printf("4. Modificar flotante 2\n");
		        	printf("5. Modificar todo\n");
	    			printf("6. Salir\n");
        			scanf("%d", &opcion);
			
    	    		if (opcion == 1) {
    		    		printf("Introduce entero nuevo:\n");
        				scanf("%d", &opcion);
    					reg.numero = opcion;
	 			
    	    		} else if (opcion == 2) {
    					char nuevoTexto[60];
    					printf("Introduce nueva cadena:\n");
    					scanf(" %[^\n]%*c", nuevoTexto);
	    				strcpy(reg.enTexto, nuevoTexto);
     				} else if (opcion == 3) {
      					float nuevofloat;
    					printf("Introduce el nuevo primer flotante:\n");
    					scanf("%f", &nuevofloat);
    					reg.magic[0] = nuevofloat;
    				} else if (opcion == 4) {
    					float nuevofloat;
    					printf("Introduce el nuevo primer flotante:\n");
    					scanf("%f", &nuevofloat);
    					reg.magic[1] = nuevofloat;
    				} else if (opcion == 5) {
    					printf("Introduce entero nuevo:\n");
        				scanf("%d", &opcion);
    					reg.numero = opcion;
    					char nuevoTexto[60];
    					printf("Introduce nueva cadena:\n");
    					scanf(" %[^\n]%*c", nuevoTexto);
    					strcpy(reg.enTexto, nuevoTexto);
    					float nuevofloat;
    					printf("Introduce el nuevo primer flotante:\n");
    					scanf("%f", &nuevofloat);
    					reg.magic[0] = nuevofloat;	
    					printf("Introduce el nuevo primer flotante:\n");
    					scanf("%f", &nuevofloat);
    					reg.magic[0] = nuevofloat;	
   
    				} else if (opcion == 6) {

	    				break;
    				}
        		}
	        } else if (opcion == 3) {
	    		while (1) {
	    	    	printf("Opciones\n");
	        		printf("1. Borrar entero:\n");
	    	    	printf("2. Borrar cadena de caracteres:\n");
        			printf("3. Borrar flotante 1\n");
    	    		printf("4. Borrar flotante 2\n");
		        	printf("5. Borrar todo\n");
		    	    printf("6. Salir\n");
        			scanf("%d", &opcion);		
			
    			    if (opcion == 1) {
		        		reg.numero = -1;
	        		} else if (opcion == 2) {
        				strcpy(reg.enTexto, "");
		        	} else if (opcion == 3) {
	        			reg.magic[0] = -1.0;
         			} else if (opcion == 4) {
		         		reg.magic[1] = -1.0;
	        		} else if (opcion == 5) {
        				reg.numero = -1;
        				strcpy(reg.enTexto, "");
    		     		reg.magic[0] = -1.0;
    	     			reg.magic[1] = -1.0;
    		    	} else if (opcion == 6) {
	         			break;
        			}
    			}
		
    		} else if (opcion == 4) {
				break;
			}
		}

	}
   fclose(fd);
   return 0;
}