#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int x;
 struct nodo *der,*izq;}nodo;
 typedef nodo *arbol;

void cargarnodo(arbol *arbolito, int x);
int suma3(arbol a);
int hojas (arbol a);
int esta (arbol a, int y);

int main()
{
 arbol a;
 int x,y;

 printf("ingrese"); scanf("%d",&x);
 while( x != 0 ){
    cargarnodo(&a,x);
    printf("ingrese"); scanf("%d",&x);
 }
 printf("ingrese y");scanf("%d",&y);
 printf("%d\n",suma3(a));
 printf("%d\n",hojas(a));
 printf("%d",esta(a,y));


 return 0;
}

int esta (arbol a, int y){
 if (a == NULL)
    return 0;
 else
    if ( a->x == y )
     return 1;
    else
     return esta(a->izq,y) || esta(a->der,y);
}

int hojas( arbol a ){
    if ( a == NULL)
        return 0;
    if ( a->izq == NULL && a->der == NULL)
        return 1;
    return hojas(a->izq) + hojas(a->der);
}

int suma3(arbol a){
 if (a == NULL)
    return 0;
 else{
    if(a->x % 3 == 0)
        return a->x + suma3(a->izq) + suma3(a->der);
    else
     return suma3(a->izq) + suma3(a->der);
 }



}

void cargarnodo(arbol *arbolito, int x){
 if( *arbolito == NULL ){
    *arbolito = (arbol)malloc(sizeof(nodo));
    (*arbolito)->x=x;
    (*arbolito)->izq=NULL;
    (*arbolito)->der=NULL;
 }
else
    if (x > (*arbolito)->x)
        cargarnodo(&((*arbolito)->der),x);
    else
        cargarnodo(&((*arbolito)->izq),x);
}
