/*Escribir programas, en lenguaje C, para:
a. Determinar el mayor de tres números.
*/

#include <stdio.h>

int main(void){
	
	float num1,num2,num3;
	
	printf("Escriba tres numeros por pantalla \n");
	scanf("%f %f %f",&num1,&num2,&num3);
	
	if(num1>num2 && num1>num3){
		if(num2>num3){
			
			printf("El numero mayor de todos es %2.f \n",num1);
			printf("El numero intermedio es %2.f \n",num2);
			printf("El numero menor es f.2",num3);
			
		}else{
			
			printf("El numero mayor de todos es %2.f \n",num1);
			printf("El numero intermedio es %2.f \n",num3);
			printf("El numero menor es %2.f",num2);
			
		}
	}else if (num2>num1 && num2>num3){
		if(num1>num3){
			
			printf("El numero mayor de todos es %2.f \n",num2);
			printf("El numero intermedio es %2.f \n",num1);
			printf("El numero menor es %2.f",num3);
			
		}else{
			
			printf("El numero mayor de todos es %2.f \n",num2);
			printf("El numero intermedio es %2.f \n",num3);
			printf("El numero menor es %2.f",num1);
			
		}
	}else if (num3>num1 && num3>num2){
		if(num1>num2){
			
			printf("El numero mayor de todos es %2.f \n",num3);
			printf("El numero intermedio es %2.f \n",num1);
			printf("El numero menor es %2.f",num2);
			
		}else{
			
			printf("El numero mayor de todos es %2.f \n",num3);
			printf("El numero intermedio es %2.f \n",num2);
			printf("El numero menor es %2.f",num1);
			
		}
	}
	
	
	
}
