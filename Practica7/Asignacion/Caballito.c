#include <stdio.h>
#include <stdlib.h>


extern int N=0;

// Con esta función verificamos si i, j son índices válidos    para tablero de ajedrez N * N
/*casillaso permitimos movimientos que sean menores que la matriz del tablero y movimientos que no se hayan realizado, por eso -1*/
int validar(int x, int y, int casillas[N][N])
{
	return (x >=0 && x < N && y >= 0 && y < N && casillas[x][y] == -1);  
}

/* imprimir las casillas por donde pasa el caballo */
void MostrarRecorrido(int casillas[N][N]){
	int x,y;

	for (x = 0; x < N; x++) {
		for (y = 0; y < N; y++)
			printf(" %2d ", casillas[x][y]+1); // imprimir ruta del caballo
		printf("\n");
	}
}

/* Esta función utiliza principalmente MovCaballo ()
para recasillasver el problema. Devuelve falso si no están completa las casillas
 es posible, de lo contrario devuelve verdadero e imprime el
excursión.
Tenga en cuenta que puede haber más de una casillasución,
esta función imprime una de las casillasuciones factibles. */

int tablero(int N){
	
int casillas[N][N]; // creamos la matriz con el orden NxN que representa nuestro tablero de ajedrez
register int x,y;
	/* Inicialización de matriz */
	for(x = 0; x < N; x++)
		for (y = 0; y < N; y++)
			casillas[x][y] = -1;

	/* xMove [] y yMove [] definen el siguiente movimiento del caballo
	xMove [] es para el siguiente valor de la coordenada x
	yMove [] es para el siguiente valor de la coordenada y 
	asignamos con esto la posicion de la siguiente casilla donde estara el caballo
	*/
	
	// 8 posibles movimientos
	int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
	int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Colocamos el caballo en la primera casilla
	casillas[0][0] = 0;

	/* Empezamos desde 0,0 y hacemos los recorridos utilizando MovCaballo () */
	if (MovCaballo(0, 0, 1, casillas, xMove, yMove) == 0) {
		printf("La solucion de movimientos permitidos no existe");
		return 0;
	}
	else
		MostrarRecorrido(casillas);

	return 1;
}

//funcion para realizar cada paso del caballo por la matriz
int MovCaballo(int x, int y, int movimientos, int casillas[N][N],int xMove[N], int yMove[N]){
	int i, next_x, next_y;
	
	if (movimientos == N * N)
		return 1;

	/*insertamos todos los siguientes movimientos desde la coordenada actual x, y	*/
	for (i = 0; i < 8; i++) {
		next_x = x + xMove[i]; // movimientos de nuestra secuencia permitida del arreglo
		next_y = y + yMove[i]; // movimientos de nuestra secuencia permitida del arreglo
		
		if (validar(next_x, next_y, casillas)) {
			casillas[next_x][next_y] = movimientos; // donde recorremos colocamos una marca
			if (MovCaballo(next_x, next_y, movimientos + 1, casillas,xMove, yMove)== 1)
				return 1;
			else
				casillas[next_x][next_y] = -1; // ruta del backtracking
		}
	}

	return 0;
}


int main()
{	
	
	printf("Escriba el orden NxN del tablero de ajedrez \n");
	scanf("%i",&N);
	
	tablero(N); //le enviamos a la funcionel orden de la matriz
	return 0;
}

