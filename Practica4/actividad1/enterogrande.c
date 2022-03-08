#include<stdio.h>
#include<string.h>

int num1[]={1,9,1,3,4};
int num2[]={1,4};
int cifras[10];

int main() {
    int l=0;
    int l2=0;
    int mult=0;
    int t=0;
    int g=0;
  int a= (sizeof(num1)/ sizeof(int))-1; // longitud Num1
  int b= (sizeof(num2)/ sizeof(int))-1; // longitud Num2
  int d=(sizeof(cifras)/ sizeof(int))-1; // Longitud de cifras
  
  int k;
  for ( k=0;k<d+1;k++){
      cifras[k]=0;
  }
  
  int j;
  
  for(t=b;t>-1;t--){
      for( j=a;j>-1;j--){ 
      
          mult=num1[j] * num2[t]; // multiplicacion de caracteres
          cifras[d-l-g]=cifras[d-l-g]+mult; // agregar multiplicacion en el arreglo
         
          if (cifras[d-l-g]>=10){ // si se supera el nro 10, arreglamos el numero
              cifras[d-g-l-1]=cifras[d-g-l-1]+(cifras[d-l-g]/10);
              cifras[d-l-g]=cifras[d-l-g]%10;
             
          }
          g++;
      }
      g=l2;
      l++;
  }
     
for (k=0;k<d+1;k++){ // imprimos la multiplicacion
 printf("%d",cifras[k]);
 }
 
    return 0;
}
