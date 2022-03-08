/*Realice, en lenguaje C, una función que realice la conversión entre unidades.
// convertir: retorna el resultado de convertir
// el valor expresado en unidad1 a la unidad2

float convertir(float valor, int unidad1,int unidad2);
Por ejemplo:
#define MILIMETROS 1
#define CENTIMETROS 2
#define METROS 3
#define KILOMETROS 4
#define PULGADAS 5
#define PIES 6
#define YARDAS 7
#define MILLAS 8
…
float v_origen,v_destino;
…
v_destino = convertir(v_origen, METROS, PIES);
Adicionalmente, puede asumir que cuentas con definiciones con los factores
de conversión:
#define METROS2CENTIMETROS 100.0
#define PULGADAS2CENTIMETROS 2.54
…
#define PIES2PULGADAS 12.0*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MILIMETROS 1
#define CENTIMETROS 2
#define METROS 3
#define KILOMETROS 4
#define PULGADAS 5
#define PIES 6
#define YARDAS 7
#define MILLAS 8

//CONVERSION MILIMETROS
#define MILIMETROS_CENTIMETROS 10        // Dividir entre 10
#define MILIMETROS_METROS 1000          // dividir entre 1000
#define MILIMETROS_KILOMETROS 1000000  // dividir entre 1000.000
#define MILIMETROS_PULGADAS 25.4        // Dividir entre 25.4
#define MILIMETROS_PIES 305.0        // dividir 305, valor aprox
#define MILIMETROS_YARDAS 914.0     // dividir 914.0 valor aprox
#define MILIMETROS_MILLAS 1.60     // dividir entre 1,60

// CONVERSION CENTIMETROS
#define CENTIMETROS_MILIMETROS 10        // multiplicar
#define CENTIMETROS_METROS 100 	    	// divide entre 100
#define CENTIMETROS_KILOMETROS 100000  // divide entre 100000
#define CENTIMETROS_PULGADAS 2.54     // divide entre 2.54
#define CENTIMETROS_PIES 30.48       // divide entre 30,48 
#define CENTIMETROS_YARDAS 91.44    // divide entre 91,44
#define CENTIMETROS_MILLAS 160934  // divide entre 160934 valor aprox

// CONVERSION METROS
#define METROS_MILIMETROS 1000     // multiplicar por 1000
#define METROS_CENTIMETROS 100    // multiplicar por 100
#define METROS_KILOMETROS 1000   // dividir entre 1000
#define METROS_PULGADAS 39.37   // multiplica por 39,37
#define METROS_PIES 3.281      // multiplicar por 3,281
#define METROS_YARDAS 1.09361 // multiplica por 1.09361
#define METROS_MILLAS 1609    // divide entre 1609

// CONVERSION KILOMETROS
#define KILOMETROS_MILIMETROS 999996.984   // dividir entre 999996.984
#define KILOMETROS_CENTIMETROS 100000     // multiplica el valor por 100000
#define KILOMETROS_METROS 1000           // multiplica por 1000
#define KILOMETROS_PULGADAS 39370       // multiplica 39370
#define KILOMETROS_PIES 3281           // multplica por 3281
#define KILOMETROS_YARDAS 1094        // multiplica por 1094
#define KILOMETROS_MILLAS 1.609      // divide entre 1,609


// CONVERSION PULGADAS
#define PULGADAS_MILIMETROS 25.4        // multiplicar por 25,4
#define PULGADAS_CENTIMETROS 2.54      // multiplica por 2.54
#define PULGADAS_METROS 39.37         // divide entre 39,37
#define PULGADAS_KILOMETROS 39370    // divide entre 39370
#define PULGADAS_MILLAS 63360       // divide entre 63360
#define PULGADAS_PIES 12           // divide entre 12
#define PULGADAS_YARDAS 36        // divide entre 36

//CONVERSION PIES
#define PIES_MILIMETROS 305       // multiplicar por 305
#define PIES_CENTIMETROS 30.48   // multiplica por 30,48
#define PIES_METROS 3.281       // divide entre 3,281
#define PIES_KILOMETROS 3281   // divide entre 3281
#define PIES_PULGADAS 12      // multiplicar por 12
#define PIES_MILLAS 5280     // divide entre 5280
#define PIES_YARDAS 3       // divide entre 3

//CONVERSION YARDAS
#define YARDAS_MILIMETROS 914     // multiplicar por 914
#define YARDAS_CENTIMETROS 91.44 // multiplicar por 91,44
#define YARDAS_METROS 1.094     // divide entre 1,094
#define YARDAS_KILOMETROS 1094 // divide entre 1094
#define YARDAS_PULGADAS 36    // multiplicar por 36
#define YARDAS_PIES 3        // multiplicar por 3
#define YARDAS_MILLAS 1760  // dividir entre 1760

//CONVERSION MILLAS
#define MILLAS_MILIMETROS 1.60         // multiplicar por 1,60
#define MILLAS_CENTIMETROS 160934     // multiplicar por 160934
#define MILLAS_METROS 1609           // multiplicar por 1609
#define MILLAS_KILOMETROS 1.609     //multiplicar  1,609
#define MILLAS_PULGADAS 63360      // multiplicar por 63360
#define MILLAS_PIES 5280          // multiplica por 5280
#define MILLAS_YARDAS 1760       // multilicar por 1760




float convertir(float valor, int unidad1,int unidad2){
	float resultado=0;
	
	if(unidad1==MILIMETROS){ // MILIMETROS A //listo
	
	switch(unidad2){
						
			case 2: resultado=valor/MILIMETROS_CENTIMETROS; // convertir a centimetros
			break;
			
			case 3: resultado=valor/MILIMETROS_METROS; // convertir a Metros
			break;
			
			case 4: resultado=valor/MILIMETROS_KILOMETROS; // convertir a kilometros
			break;
			
			case 5: resultado=valor/MILIMETROS_PULGADAS; // convertir a pulgadas
			break;
			
			case 6: resultado=valor/MILIMETROS_PIES; // convertir a pies
			break;
			
			case 7: resultado=valor/MILIMETROS_YARDAS; // convertir a yardas
			break;
			
			case 8: resultado=valor/MILIMETROS_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==CENTIMETROS){ // CENTIMETROS A //listo 
	
	switch(unidad2){
			case 1: resultado=valor*CENTIMETROS_MILIMETROS; // convertir a milimetros
			break;
						
			case 3: resultado=valor/CENTIMETROS_METROS; // convertir a metros
			break;
			
			case 4: resultado=valor/CENTIMETROS_KILOMETROS; // convertir a kilometros
			break;
			
			case 5: resultado=valor/CENTIMETROS_PULGADAS; // convertir a pulgadas
			break;
			
			case 6: resultado=valor/CENTIMETROS_PIES; // convertir a pies
			break;
			
			case 7: resultado=valor/CENTIMETROS_YARDAS; // convertir a yardas
			break;
			
			case 8: resultado=valor/CENTIMETROS_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==METROS){ // METROS A 
		
		switch(unidad2){
			case 1: resultado=valor*METROS_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*METROS_CENTIMETROS; // convertir a centimetros
			
			break;
						
			case 4: resultado=valor/METROS_KILOMETROS; // convertir a Kilometros
			break;
			
			case 5: resultado=valor*METROS_PULGADAS; // convertir a Pulgadas
			break;
			
			case 6: resultado=valor*METROS_PIES; // convertir a Pies
			break;
			
			case 7: resultado=valor*METROS_YARDAS; // convertir a Yardas
			break;
			
			case 8: resultado=valor/METROS_MILLAS; // convertir a Millas
			break;
			
		}
		
			
	}else if(unidad1==KILOMETROS){
		
		switch(unidad2){
			case 1: resultado=valor/KILOMETROS_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*KILOMETROS_CENTIMETROS; // convertir a centimetros
			
			break;
			
			case 3: resultado=valor*KILOMETROS_METROS; // convertir a centimetros
			
			break;
									
			case 5: resultado=valor*KILOMETROS_PULGADAS; // convertir a Pulgadas
			break;
			
			case 6: resultado=valor*KILOMETROS_PIES; // convertir a Pies
			break;
			
			case 7: resultado=valor*KILOMETROS_YARDAS; // convertir a Yardas
			break;
			
			case 8: resultado=valor/KILOMETROS_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==PULGADAS){
		
		switch(unidad2){
			case 1: resultado=valor*PULGADAS_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*PULGADAS_CENTIMETROS; // convertir a centimetros
			
			break;
			
			case 3: resultado=valor/PULGADAS_METROS; // convertir a centimetros
			
			break;
			
			case 4: resultado=valor/PULGADAS_KILOMETROS; // convertir a Kilometros
			
			break;
			
			case 6: resultado=valor/PULGADAS_PIES; // convertir a Pies
			break;
			
			case 7: resultado=valor/PULGADAS_YARDAS; // convertir a Yardas
			break;
			
			case 8: resultado=valor/PULGADAS_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==PIES){
		
			switch(unidad2){
			case 1: resultado=valor*PIES_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*PIES_CENTIMETROS; // convertir a centimetros
			
			break;
			
			case 3: resultado=valor/PIES_METROS; // convertir a centimetros
			
			break;
			
			case 4: resultado=valor/PIES_KILOMETROS; // convertir a Kilometros
			
			break;
			
			case 5: resultado=valor*PIES_PULGADAS; // convertir a Pulgadas
			break;
			
			case 7: resultado=valor/PIES_YARDAS; // convertir a Yardas
			break;
			
			case 8: resultado=valor/PIES_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==YARDAS){
		
		switch(unidad2){
			case 1: resultado=valor*YARDAS_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*YARDAS_CENTIMETROS; // convertir a centimetros
			
			break;
			
			case 3: resultado=valor/YARDAS_METROS; // convertir a metros
			
			break;
			
			case 4: resultado=valor/YARDAS_KILOMETROS; // convertir a Kilometros
			
			break;
			
			case 5: resultado=valor*YARDAS_PULGADAS; // convertir a Pulgadas
			break;
			
			case 6: resultado=valor*YARDAS_PIES; // convertir a Pies
			break;
			
			case 8: resultado=valor/YARDAS_MILLAS; // convertir a Millas
			break;
			
		}
		
	}else if(unidad1==MILLAS){
		
		switch(unidad2){
			case 1: resultado=valor*MILLAS_MILIMETROS; // convertir a milimetros
			break;
			
			case 2: resultado=valor*MILLAS_CENTIMETROS; // convertir a centimetros
			
			break;
			
			case 3: resultado=valor*MILLAS_METROS; // convertir a metros
			
			break;
			
			case 4: resultado=valor*MILLAS_KILOMETROS; // convertir a Kilometros
			
			break;
			
			case 5: resultado=valor*MILLAS_PULGADAS; // convertir a Pulgadas
			break;
			
			case 6: resultado=valor*MILLAS_PIES; // convertir a Pies
			break;
			
			case 7: resultado=valor*MILLAS_YARDAS; // convertir a Millas
			break;
			
		}	
	}

	return resultado;
}



int main(){
	
	float v_destino,v_origen;
	int uni1,uni2;
	int i;
	char nombre1[11],nombre2[11];
	
	printf("Bienvenido al programa de conversiones, elige dos unidades a convertir: \n");
	printf("MILIMETROS 1 \n");
	printf("CENTIMETROS 2 \n");
	printf("METROS 3 \n");
	printf("KILOMETROS 4 \n");
	printf("PULGADAS 5 \n");
	printf("PIES 6 \n");
	printf("YARDAS 7 \n");
	printf("MILLAS 8 \n");
	
	//inicizlizar
	uni1=uni2=v_destino=v_origen=0;
	
	//inicizlizar
	for(i=0;i<11;i++){
		nombre1[i]=0;
		nombre2[i]=0;
	}
			
		printf("Digite La unidad 1 \n");
		scanf("%i",&uni1);	
		
		printf("Digite La unidad 2 \n");
		scanf("%i",&uni2);	
		
		// Definir nombre de la conversion

	
	
		switch(uni1){
		     	case 1: strcpy(nombre2,"Milimetros");
				break;
				
				case 2: strcpy(nombre2,"Centimetros");
				break;
				
				case 3: strcpy(nombre2,"Metros");
				break;
				
				case 4: strcpy(nombre2,"Kilometros");
				break;
				
				case 5: strcpy(nombre2,"Pulgadas");
				break;
				
				case 6: strcpy(nombre2,"Pies");
				break;
				
				case 7: strcpy(nombre2,"Yardas");
				break;
				
				case 8: strcpy(nombre2,"Millas");
				break;
			}
		
			switch(uni2){
		     	case 1: strcpy(nombre2,"Milimetros");
				break;
				
				case 2: strcpy(nombre2,"Centimetros");
				break;
				
				case 3: strcpy(nombre2,"Metros");
				break;
				
				case 4: strcpy(nombre2,"Kilometros");
				break;
				
				case 5: strcpy(nombre2,"Pulgadas");
				break;
				
				case 6: strcpy(nombre2,"Pies");
				break;
				
				case 7: strcpy(nombre2,"Yardas");
				break;
				
				case 8: strcpy(nombre2,"Millas");
				break;
			}
				
			printf("Escriba el valor %s que desea convertir a %s \n",nombre1,nombre2);	
			scanf("%f",&v_origen);
			v_destino = convertir(v_origen, uni1, uni2);
			
			printf("la conversion de %s a %s es: %.2f",nombre1,nombre2,v_destino);

	return 0;
}
