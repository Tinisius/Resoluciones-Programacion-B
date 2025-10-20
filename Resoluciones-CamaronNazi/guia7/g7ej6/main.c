#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo{
    char dato[11];
    struct nodo *der,*izq;}nodo;
typedef nodo *arbol;

int obtnivel (arbol a );
void nivelcadelarg(arbol a, int nvactual, int *nivelmax, int *longmax);

int main()
{
arbol a;
printf("nivel cadena mas larga con inicial a (-1 si no hay) %d",obtnivel(a));


}

void nivelcadelarg(arbol a, int nvactual, int *nivelmax, int *longmax){
int largo;
 if (a != NULL){
    if (a->dato[0] == 'a'){
        largo=strlen(a->dato);
        if (largo > *longmax){
            *longmax=largo;
            *nivelmax=nvactual;
        }
    }
        nivelcadelarg(a->izq,nvactual+1,nivelmax,longmax);
        nivelcadelarg(a->der,nvactual+1,nivelmax,longmax);
 }


}

int obtnivel (arbol a ){
 int longmax=0;
 int nivelmax=-1;
 nivelcadelarg(a,0,&nivelmax,&longmax);
 return nivelmax;

}
