#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
 int dato;
 struct nodo *izq;
 struct nodo *der;} nodo;
typedef nodo *tarbol;

void cargarnodo(tarbol *arbolito, int x);
void mostrar(tarbol arbolito);

int main()
{
 int x;
 char lado;
 tarbol arbolito = NULL; // no usa tda!!!!!!!!!!!
 printf("ingrese"); scanf("%d",&x);
 while( x != 0 ){
    cargarnodo(&arbolito,x);
    printf("ingrese"); scanf("%d",&x);
 }

 mostrar(arbolito);
 return 0;
}

void mostrar(tarbol arbolito){

if (arbolito != NULL){
    printf("%d\n",arbolito->dato);
    mostrar(arbolito->izq);
    mostrar(arbolito->der);
 }
}

void cargarnodo(tarbol *arbolito, int x){
 if( *arbolito == NULL ){
    *arbolito = (tarbol)malloc(sizeof(nodo));
    (*arbolito)->dato=x;
    (*arbolito)->izq=NULL;
    (*arbolito)->der=NULL;
 }
else
    if (x > (*arbolito)->dato)
        cargarnodo(&((*arbolito)->der),x);
    else
        cargarnodo(&((*arbolito)->izq),x);
}
