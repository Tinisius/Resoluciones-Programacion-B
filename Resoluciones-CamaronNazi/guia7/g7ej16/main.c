#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
int x;
struct nodo *der,*izq;}nodo;
typedef nodo *arbol;
void insertarabb(arbol *a, int y);

int main(){
arbol a;
int dato;

 printf("ingrese dato a insertar ");
 scanf("%d",&dato);
 insertarabb(&a,dato);
 return 0;
}

void insertarabb(arbol *a, int y){

while (*a != NULL){

 if ( y > (*a)->x)
    *a=(*a)->der;
 else
    *a=(*a)->izq;

}
*a=(arbol)malloc(sizeof( nodo));
(*a)->x=y;
(*a)->der=NULL;
(*a)->izq=NULL;
}
