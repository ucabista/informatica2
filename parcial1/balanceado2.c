/*Que dado un string con una secuencia de paréntesis (que abren y cierran
en cualquier orden) verifique que están balanceados y dispuestos
correctamente.
Ejemplo
()()((())) - Correcto
())() - Incorrecto
((()) - Incorrecto*/

#include<stdio.h>
#include<string.h>

int balanceado(char cadena[20],int longitud);

int main(){
	
	int resultado=0,longitud;
	
	//CASOS
 //	char parentesis[20]="()()((()))"; // correcto
 //	char parentesis[20]="())()"; // incorrecto
 //	char parentesis[20]="((())"; // incorrecto
 
 char parentesis[20]="()())())"; // caso especial incorrecto
		
	// obtener parentesis
    //printf("Escriba parentesis abiertos y cerrados");
	//gets(parentesis);
	
	longitud=strlen(parentesis);
	
	resultado = balanceado(parentesis,longitud);
	
	if (resultado==1){
	printf("El resultado de %s es Correcto",parentesis);	
	}else if(resultado==0){
		printf("El resultado de %s es Incorrecto",parentesis);
	}
	
	return 0;
}

int balanceado(char cadena[20],int longitud){
	int izq=0,der=0,i;
		
	if(longitud % 2 == 0){ // si es impar su longitud entonces no son balanceados	
	for (i=0;i<longitud;i++){
	
		if(cadena[i]=='('){
			izq++;
			}else if(cadena[i]==')'){
			der++;	
				if(cadena[i]==')' && cadena[i+1]=='(' && (izq+der)%2 > 0 ){ // verificar caso  )( si encontramos )( y hasta ahora no se han cerrado los anteriores parentesis, entonces no estan balanceados
					return 0;
				} 
			}
		}
			
	}else{
		return 0; // si la division de su longitud es impar no son balanceados
	}
		
	if(izq == der){
		return 1;
	}else{
		return 0;
	}
	
}
