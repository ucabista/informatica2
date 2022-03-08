#include<stdio.h>
#include<stdlib.h>


int misterio(int x){
	return(!x)?x:misterio(x>>3)*10+(x&7);
}
//convertir los numeros de decimal a base octal, ese es el misterio jaja
int main(){
	
	int resultado=0;
	misterio(3);
	resultado=misterio(10);
	printf("misterio es: %i",resultado);
	
	
	return 0;
}
