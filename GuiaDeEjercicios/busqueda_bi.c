// ejercicio 8 (Busqueda BINARIA o Dicotonica)
// Escriba una función en C, verifique la existencia de un elemento en un arreglo

// (Busqueda Binaria) (todos los elementos deben estar ordenadas en forma ascendente)
// (Busqueda Secuencial) (pueden estar desordenados los elementos)

int main(){
	
int a[5]={1,2,3,4,5};
int inferior,sup,mitad,dato;
char band = 'F';

dato = 6;

// BUSQUEDA BINARIA

inferior=0;
sup=5; 
while(inferior<=sup){
	mitad = (inferior+sup)/2;
	
	if(a[mitad]==dato);
	band = 'V';
	break;
	
	if(a[mitad]>dato){
		sup = mitad;
		mitad = (inferior+sup)/2;
		
	}
	if(a[mitad]<dato){
		inferior = mitad;
		mitad=(inferior+sup)/2;
	}
}
	
if(band=='F'){
		printf("El numero no existe");
	}else if(band=='V'){
		printf("el numero si existe en la posicion %i",mitad);
	}
	
	return 0;
}

