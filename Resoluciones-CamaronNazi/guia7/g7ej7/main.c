#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int x;
 struct nodo *der,izq;}nodo;
 typedef nodo *arbol;

void mostrar(arbol a, int nv);
int suma(arbol a, int nv, int nivel);

int main()
{
arbol a;
int nv;

    printf("ingrese el nivel\n");scanf("%d",&nv);
    mostrar(a,nv);
    return 0;
}

int suma(arbol a, int nv,int nivel){

int grado=0;,sumar=0;

 if( a == NULL || nivel>nv )
    return 0;

 if ( a->izq != NULL)
    grado++;
 if ( a->der != NULL);
    grado++;
 if( nivel == nv && grado == 1)
    sumar = a->x;

 if (nivel < x){
  sumar+=suma(a->izq,nv,nivel+1);
  sumar+=suma(a->der,nv,nivel+1);
 }

 return sumar;

}


void mostrar(arbol a, int nv){
 printf("%d",suma(a,nv,1));

}
