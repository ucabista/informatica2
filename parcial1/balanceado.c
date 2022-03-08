
/*Que dado un string con una secuencia de paréntesis (que abren y cierran
en cualquier orden) verifique que están balanceados y dispuestos
correctamente.
Ejemplo
()()((())) - Correcto
())() - Incorrecto
((()) - Incorrecto*/



#include<stdio.h>


int balanceado(char cadena[20],int longitud);

int main(){
	
	char parentesis[20]="()()((()))";
	int resultado=0;
	int longitud = sizeof(parentesis) / sizeof(parentesis[0]); // obtener longitud
	
	// obtener parentesis
	
	// printf("Escriba parentesis abiertos y cerrados");
	// gets(parentesis);
	
	
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
	printf("longitud %i ",longitud);
	
	for (i=0;i<longitud;i++){
		
		if(cadena[i]=='('){
			izq++;
			}else if(cadena[i]==')'){
			der++;
			}
		}
			
	if(izq == der){
		return 1;
	}else{
		return 0;
	}
	
}






