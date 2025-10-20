#include <stdio.h>
#include <stdlib.h>
#define infinito 3000
typedef struct nodo{
 int x;
 struct nodo *der,*izq;}nodo;
typedef nodo *arbol;

int esabb(arbol a, int min, int max);
void addnodo(arbol *a, int e);
void cargarArbol(arbol *a);

int main()
{
 arbol a;

  cargarArbol(&a);
 if ( esabb(a,-infinito,+infinito))
    printf("es abb");
 else
    printf( "no es abb");
    return 0;
}

int esabb(arbol a, int min, int max){
 if (a != NULL){

    if (a->x <= min || a->x>=max)
        return 0;

    else
        return esabb(a->izq,min,a->x) && esabb(a->der,a->x,max);
 }
 else
    return 1;
}

void cargarArbol(arbol *a){
    addnodo(a, 8);
    addnodo(&(*a)->izq, 50);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->der, 5);
    addnodo(&(*a)->der, 14);
    addnodo(&(*a)->der->izq, 10);
    addnodo(&(*a)->der->izq->der, 12);
    addnodo(&(*a)->der->der, 22);
}

void addnodo(arbol *a, int e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->x = e;
    (*a)->izq = (*a)->der = NULL;
}
