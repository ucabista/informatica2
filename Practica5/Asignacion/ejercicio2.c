/*Implemente función char *itotext(const int v, char *d),
que convierte a v en texto. Por ejemplo itotext(15, str) deja en el
buffer apuntado por str “Quince”. Así mismo la función debe
trabajar, al menos, con valores desde 0 hasta 999,999,999 y el string
debe comenzar con mayúscula. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Una función que imprime un número dado en palabras. */
void itotext(char* num)
{
	int len = strlen(num); // Obtener la longitud de los numeros
	int pos=0; // posicion de cifras
	int i=0;
	/* Casos Bases */
	if (len == 0) {
		printf("Cadena Vacia\n");
		return;
	}else if (len > 9) {
		printf("No se permite una longitud superior a 9 \n");
		return;
	}

	// unidades de cifras
	char* Unidades[]= { "Cero", "Uno", "Dos", "Tres", "Cuatro","Cinco", "Seis", "Siete", "Ocho", "Nueve" };

	// espacio vacio que esta para mantener un orden con las posiciones, con cada caracter
	char* nros_Diez[] = {" ","Diez","Once","Doce","Trece","Catorce", "Quince", "DieciSeis","DieciSiete", "DieciOcho", "DieciNueve" };
	
	// digitos decenas
	char* decenas_Digitos[] = { " ", " ","Veinti","Treinta", "Cuarenta", "Cicuenta","Sesenta","Setenta", "Ochenta","Noventa" };
	//miles,millones,cientos
	char* milesimas[] = {" ", "Mil","Millones","Cientos"};
	//centenas
	char* centenas[] = {" ","Cien", "Dos Cientos","Tres Cientos","Cuatro Cientos","Quinientos","Seis Cientos","Sete Cientos","Ocho Cientos","NoveCientos"};

	printf("\n %s: ", num); // imprimir numero, que luego sera pasado a letras

	/* Para un número de un solo dígito */
	if (len == 1) {
		pos=*num - '0'; // obtener posicion inicial
		printf("%s", Unidades[pos]);
		return;
	}

	/* iterar mientras sea diferente de vacio para recorrer cada cifra*/
	while (*num != '\0') {
		
		if(len==9){ 
		
			pos=*num - '0'; //obtener primer caracter:
			
			if(pos==1){
				printf("%s ",milesimas[3]); // si es 1. es cientos
			}else{
				printf("%s ",centenas[pos]);	
			}
			pos= *(num+1) - '0'; // segundo caracter
			if(pos!=1){
				printf("%s ",decenas_Digitos[pos]);
			}else{ // 999.999,999
				printf("%s ",nros_Diez[*(num+2)-'0']);
			}
			
			pos=*(num+2) - '0'; // tercer caracter
			if(pos!=0){
				printf(" y %s ",Unidades[pos]);
				printf("%s ",milesimas[2]);
			}
			
			pos= *(num+3) - '0'; // cuarto caracter
			if(pos!=0){
				printf("%s ",centenas[pos]);
			}
			pos= *(num+4) - '0'; // cuarto caracter
			if(pos!=1){
				printf("%s ",decenas_Digitos[pos]);
			}else{ // 999.999,999
				printf("%s ",nros_Diez[*(num+2)-'0']);
			}
						
			pos= *(num+4) - '0'; // quinto caracter
			if(pos!=0){
				
				printf("%s",Unidades[pos]);	
			}
			if(*num - '0' != '0' && *(num+1) - '0'!= '0'){
				
				printf("%s ",milesimas[1]);
			}
			
			pos= *(num+5) - '0'; // sexto caracter
			if(pos!=0){
				printf("%s ",centenas[pos]);
			}
			pos= *(num+6) - '0'; // septimo caracter
			if(pos!=1){
				printf("%s ",decenas_Digitos[pos]);	
			}else{
				printf("%s ",nros_Diez[pos]);	
			}
			
			pos= *(num+8) - '0'; // Octavo caracter 999.999.999
			if(pos!=0){
			printf("y %s ",Unidades[pos]);	
			}
							
			return;
		}
		
		if(len==8){ 
		
			pos=*num - '0'; //obtener primer caracter:
			
			if(pos!=1){
				printf("%s ",decenas_Digitos[pos]);
			}else{
				printf("%s ",nros_Diez[pos]);
			}
			
			
			pos= *(num+1) - '0'; // segundo caracter
			if(pos!=0){
				printf("%s ",Unidades[pos]);
				printf("%s ",milesimas[2]);	
			}else{
				printf("%s ",milesimas[2]);
			}
			
			pos= *(num+2) - '0'; // tercer caracter
			if(pos!=0){
				printf("%s ",centenas[pos]);
			}
			
			pos= *(num+3) - '0'; // cuarto caracter
			if(pos!=0){
				printf("%s ",Unidades[pos]);
			}
		
			if(*num - '0' != '0' && *(num+1) - '0'!= '0'){
				
				printf("%s ",milesimas[1]);
			}
			pos= *(num+4) - '0'; // quinto caracter
			if(pos!=0){
				
				printf("%s",Unidades[pos]);	
			}
			
			pos= *(num+5) - '0'; // sexto caracter
			if(pos!=0){
				printf("%s ",centenas[pos]);
				printf("%s ",decenas_Digitos[pos]);	
			}
			pos= *(num+6) - '0'; // septimo caracter
			if(pos!=0){
				printf("y %s ",Unidades[pos]);	
			}
					
			return;
		}
		
		if(len==7){ 
		
			pos=*num - '0'; //obtener primer caracter:
			
			if(pos!=1){
			printf("%s ", Unidades[pos]);
			printf("%s ",milesimas[2]);	
			}else{
				printf("Un Millon ");
			}
			
			
			pos= *(num+1) - '0'; // segundo caracter
			
			if(pos==1 && pos!= 0){
			printf("%s ",milesimas[3]); // 1 cientos
		}else{
			printf("%s ",centenas[pos]);		
			} 
			
			pos= *(num+2) - '0'; // tercer caracter
			if(pos!=0){
				printf("%s ",decenas_Digitos[pos]);
			}
			
			pos= *(num+3) - '0'; // cuarto caracter
			if(pos!=0){
				printf("%s ",Unidades[pos]);
			}
			
			pos= *(num+1) - '0'; // verificar si hay nro en 2do caracter para colocar Mil
			if(pos!=0){ //
				printf("%s ",milesimas[1]);
			}
			pos= *(num+4) - '0'; // quinto caracter
			if(pos!=0){
				printf("%s ",centenas[pos]);	
			}
			pos= *(num+5) - '0'; // sexto caracter
			if(pos!=0){
				printf("%s ",decenas_Digitos[pos]);	
			}
			pos= *(num+6) - '0'; // septimo caracter
			if(pos!=0){
				printf("y %s ",Unidades[pos]);	
			}
					
			return;
		}
	
	if(len==6){ 
		
			pos=*num - '0'; // obtener primer caracter
			printf("%s ", centenas[pos]);
			
			if(num[1]!='0'){
				pos=*(num+1)-'0';
				printf("%s ", decenas_Digitos[pos]);	
			}
			if(num[1]=='1'){
				pos=*(num+1)-'0'; //obtener segundo caracter
				printf("%s ", nros_Diez[pos]);
			}
			if(num[2]!='0'){
				pos=*(num+2)-'0';
				printf("%s ", Unidades[pos]);
			}
			printf("%s ",milesimas[len - 5]);
			
			if(num[3]!='0'){
				pos=*(num+3)-'0';
				printf("%s ",centenas[pos]);
			}
			if(num[4]!='0'){
				pos=*(num+4)-'0';
				printf("%s ",decenas_Digitos[pos]);
			}
			if(num[5]!='0'){
				pos=*(num+5)-'0';
				printf("y %s ",Unidades[pos]);
			}
			
		return;
		}
		
    	if(len==5){ 
		 
		 	pos=*num - '0'; // obtener primer caracter
		 	
		 	if(pos!=1){
		 		printf("%s ",decenas_Digitos[pos]);	
			 }else{
			 	pos=*(num+1)-'0'; // segundo caracter
			 	printf("%s ",nros_Diez[pos+1]);
			 }

			pos=*num - '0'; // obtener primer caracter
			if(pos!=1){
				pos=*(num+1)-'0'; // segundo caracter
				if(pos!=0){
					printf("%s ",Unidades[pos]);
				}
			}
		
			printf("%s ",milesimas[1]); // miles
			if(pos!=0){
						
			pos=*(num+2)-'0'; // tercer caracter
			printf("%s ", centenas[pos]);
			
			pos=*(num+3)-'0'; // cuarto caracter
			printf("%s ",decenas_Digitos[pos]);
			
			}
			// ultima unidad
			pos=*(num+4)-'0'; // quinto caracter
			if(pos!=0){
			printf("%s",Unidades[pos]);
			}
		
		return;	
	}
	if(len==4){ // 1000
		
		int pos=*num - '0'; // obtener primer caracter
			
		if(num[0]!='0' && num[0]!='1'){
				printf("%s ", Unidades[pos]); // no imprimir si comienza por 1	
			}
				printf("%s ",milesimas[1]); // miles
				
				pos=*(num+1)-'0'; // segundo caracter
				printf("%s ",centenas[pos]);
				pos=*(num+2)-'0'; // tercer caracter
				printf("%s ",decenas_Digitos[pos]);
				pos=*(num+3)-'0'; // cuarto caracter, unidad
				
				if(pos!=0){
					printf("%s", Unidades[pos]);
				}
				
			return;	
		}else if(len >= 3) { /* Primeros dos digitos */ 
		
		int pos = *num+0 - '0'; // posicion incial de caracter
		
		if(*num+0 - '0' =='1' && *(num+1) - '0'=='0'){ // imprimir si es Cien
			printf("%s ",centenas[pos]);
		}
			if (*num - '0' != 0) {
				printf(" %s",centenas[pos]);  
				
				if(num[1]!='0' && num[2] !='0'){ 
					pos = *(num+1) - '0'; // ultima posicion de caracter
					printf(" %s ", decenas_Digitos[pos]);  
					
					if(num[1]!='1'){
						pos = *(num+2) - '0'; // ultima posicion de caracter
						printf(" y ");
						printf("%s ",Unidades[pos]); 
						
						}					
					}
					
					if(num[1]=='0' && num[2] !='0'){ // ultima cifra
					pos = *(num+2) - '0'; // ultima posicion de caracter
						printf(" %s ",Unidades[pos]);
					}
					
			return;
		}
	}
		
		/* dos digitos */
		else {
			/* dos digitos de 10-19 */
			if (*num == '1') {
				int sum = *num - '0' + *(num + 1) - '0';
				printf("%s", nros_Diez[sum]);
				return;
			}

			/* mostrar 20 si lo encontramos*/
			else if (*num == '2' && *(num + 1) == '0') {
				printf("Veinte \n");
				return;
			}else { /* El resto de los números de dos dígitos del 21 al 99	*/
				i = *num - '0';
				if(i==0){
					printf("%s",decenas_Digitos[i]);
				}else{
					printf("");
				} 
				++num;
				if (*num != '0'){
					
					printf("%s ",Unidades[*num - '0']);
				}
			}
		}
	  ++num;
	} // fin ciclo while
}


int main(void)
{
	
	itotext("");
	itotext("1");
	itotext("10");
	itotext("100");
	itotext("300");
	itotext("305");
	itotext("355");
	itotext("310000");
	itotext("322281");
	itotext("3000000");
	itotext("1150000");
	itotext("3200000");
	itotext("3230000");
	itotext("3233000");
	itotext("80800000");
	itotext("10800000");
	itotext("999999999");
	itotext("999999990");
	itotext("199995990");
		
	return 0;
}

