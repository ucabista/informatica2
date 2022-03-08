#include<stdio.h>

#define SIZE 8

void finder(int array[], int major, int in){
	if (in==SIZE) 
		printf("El  mayor de todos es: %i", major);;
	
	if (in<SIZE){
		if (array[in]>major)
			major=array[in];
		finder(array, major, in+1);
	}

}//fin finder

int main(){
	int i;
	int vector[SIZE] = {3,4,74,2,46,352,21,8};
	
	printf("Arreglo:");
	for (i=0; i<SIZE; i++){
		printf(" %i",vector[i]);
	}
	printf("\n");
	
	finder(vector, vector[0], 0);
	
	return 0;
}
