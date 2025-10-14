#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
 int x;
 char cadena[11];
 struct nodo *der,*izq;}nodo;
typedef nodo arbol;

int nivel(arbol a );
int hijod(arbol a );
int longu(arbol a );

int main()
{
    arbol a;
    printf("%d",nivel(a));
    printf("%d",hijod(a));
    printf("%d",longu(a));
    return 0;
}

int longu(arbol a){
 if(a==NULL)
    return 0;
 else{
    int li=longu(a->izq);
    int de=longu(a->der);
    act=strlen(a->cadena);
    max=act;
    if(li>max)
        max=li;
    else{
      if(de>max)
        max=de;
    }
    return max;

 }



}

int hijod(arbol a ){
    if( a == NULL)
        return 0
    else
     if( a->der !=NULL)
      return 1+ hijod(a->der)+hijod(a->izq)
     else
      return 0;
 }
int nivel(arbol a){
int der,izq;

 if (a == NULL)
    return 0;
 else{
    izq=nivel(a->izq);
    der=nivel(a->der);
    if (izq > der)
        return 1+izq;
    else
        return 1+der;
 }

}
