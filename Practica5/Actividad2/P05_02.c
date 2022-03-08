/*
 *   UCAB - Guayana
 *   Algoritmos y Programación II
 *   Practica 05 - Actividad 03
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REG 25
#define N_INDICES 3

struct info_persona{
	int  carnet;
	char apellido[16];
	char nombre[16];
	int  ingreso;
} registros[MAX_REG];

int indice[N_INDICES][MAX_REG];

int n_reg=0;

// Imprime el encabezado para los registros

void imprime_titulo(void){
	printf("Carnet  Apellido        Nombre          Ingreso\n");
	printf("-----------------------------------------------\n");
}

// Imprime el registro de la posicion i

void imprime_registro(int reg){
	if(reg<0 || reg >= n_reg){
		fprintf(stderr,"Registro no encontrado\n");
		return;
	}
	printf("%7d %-15s %-15s %4d\n",
		registros[reg].carnet,registros[reg].apellido,
		registros[reg].nombre,registros[reg].ingreso);
}

// Lee los registros de un archivo

void leer_registros(char *nombre){
	FILE *fp;
	int i;

	if((fp=fopen(nombre,"r"))==NULL){
		fprintf(stderr,"leer_registros: No se puede abrir %s\n",nombre);
		return;
	}
	while(fscanf(fp,"%d %s %s %d",&registros[n_reg].carnet,registros[n_reg].apellido,
         registros[n_reg].nombre,&registros[n_reg].ingreso)!=EOF)
		n_reg++;
	fclose(fp);
}

// Funciones que compara los elementos de regitros por un campo
// referenciados por i y j en el indice k

int cmp_carnet(int k,int i,int j){
	return registros[indice[k][i]].carnet<registros[indice[k][j]].carnet;
}

int cmp_apellido(int k,int i,int j){
	return strcmp(registros[indice[k][i]].apellido,registros[indice[k][j]].apellido)<0;
}

int cmp_nombre(int k,int i,int j){
	return strcmp(registros[indice[k][i]].nombre,registros[indice[k][j]].nombre)<0;
}

//funcion quicksort

/*Una función de utilidad para intercambiar dos elementos*/
void swap4(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta función toma el último elemento como pivote, coloca
el elemento pivote en su posición correcta en ordenados
matriz, y coloca todos más pequeños (más pequeños que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivote
	int i = (low - 1); // Índice de elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
	int j;
	for (j = low; j <= high - 1; j++)
	{
		// Índice de elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
		if (arr[j] < pivot)
		{
			i++; // índice de incremento del elemento más pequeño
			swap4(&arr[i], &arr[j]);
		}
	}
	swap4(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* La función principal que implementa QuickSort
arr [] -> Matriz a ordenar,
bajo -> Índice de inicio,
alto -> índice de finalización */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi es índice de partición, arr [p] es ahora
en el lugar correcto */
		int pi = partition(arr, low, high);

		// Ordene los elementos por separado antes
		// partición y después de la partición
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//fin funcion quicksort



// Construye el indice K usando la funcion de comparacion cmp



void construye_indice(int k, int (*cmp)(int,int,int)){
    int i,j;

	 for(i=0;i<n_reg;i++)                     // inicializa el indice
		indice[k][i]=i;
    for(i=1;i<n_reg;i++){
    	for(j=i; j>0 && (*cmp)(k,j,j-1); j--){ //  array[j]<array[j-1]
    	   int t=indice[k][j];                 // Intercambiar

    	   indice[k][j]=indice[k][j-1];
    	   indice[k][j-1]=t;
       }
    }
}

int main(void) {
	int i,opcion;
	int (*funciones_cmp[])(int,int,int)={cmp_carnet,cmp_apellido,cmp_nombre};

	leer_registros("personas.dat");
	imprime_titulo();
	for(i=0;i<n_reg;i++)
		imprime_registro(i);
	for(i=0;i<N_INDICES;i++)
		construye_indice(i,funciones_cmp[i]);
	while(1){
		printf("\nImprimir ordenados por:");
		printf("\n\t1-Carnet 2-Apellidos 2-Nombres\n\t0-Salir\n\nOpcion (0-3) => ");
		scanf("%d",&opcion);
		if(opcion==0)
			break;
		if(opcion>=1 && opcion <=3){
			imprime_titulo();
			for(i=0;i<n_reg;i++)
				imprime_registro(indice[opcion-1][i]);
		}
		else
			printf("Error en opcion\n");
	}
	return EXIT_SUCCESS;
}
