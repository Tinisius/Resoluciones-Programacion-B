#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------------------------------------------
typedef struct NodoA{
    int dato;
    struct NodoA *izq, *der;
}NodoA;
typedef NodoA *TArbol;

int main(){
    return 0;
}
//---------------------------------------------------------------

void P5a(TArbol a, int prof, int *maxProf){
    if (a!=NULL){
        profA(a->izq, prof+1, maxprof);
        profA(a->der, prof+1, maxprof);
    }
    else
        if (prof > *maxprof)
            *maxProf=prof;
}

//---------------------------------------------------------------

void P5b(TArbol a, int *maxLen){
    if (a!=NULL){
        if (len(a->dato)>*maxlen)
            *maxLen=len(a->dato);
        maxLenA(a->izq, maxLen);
        maxLenA(a->der, maxLen);
    }
}

//---------------------------------------------------------------

void P5c(TArbol a, int *cant){
    if (a!=NULL){
        if (a->der != NULL){
            (*cant)++;
            cantHD(a->der, cant);
        }
        cantHD(a->izq, cant);
    }
}

//---------------------------------------------------------------

int P7(TArbol a, int nivel, int x){
    if (a!=NULL){
        if (nivel==x && (a->izq==NULL || a->der==NULL) && (a->izq!=a->der){ //lvl x y grado 1
            return a->dato
        }
        else
            return suma(a->izq, nivel+1, x) + suma(a->der, nivel+1, x);
    }
    else
        return 0;
}

//---------------------------------------------------------------

int P12(TArbol abb,int A, int B){
    if (abb!=NULL){
        if (abb->dato <= A)
            return P12(a->der, A, B);
        else
            if (B <= abb->dato)
                return P12(a->izq, A, B);
            else
                return 1 + P12(a->der, A, B) + P12(a->izq, A, B);;
    }
    else
        return 0;
}

//---------------------------------------------------------------

void P13 (TArbol a, v[], int *N){   //inOrden queda ordenado
    if (a!=NULL){
        P13(a->der, v, N);
        strcpy(v[N++], a->dato);
        P13(a->izq, v, N);
    }
}

//---------------------------------------------------------------

int P14(TArbol, int min, int max){  //verificar si un arbol es ABB
    if (a!=NULL){
        if (a->dato <= min || a->dato >= max)
            return 0;
        else
            return P14(a->izq, min, a->dato) && P14(a->der, a->dato, max);
    }
    else
        return 1;
}

//---------------------------------------------------------------

void P16 (TArbol *A, int x){    //A es un puntero a puntero entonces *A es un puntero a nodo

    TArbol *act = A;  //guardo en act el puntero al puntero del siguiente (izq o der)

    while (*act != NULL){
        if (x < (*act)->dato)
            act = &((*act)->izq);
        else
            act = &((*act)->der);
    }

    *act = (TArbol)malloc(sizeof(NodoA));
    (*act)->dato = x;
    (*act)->izq = (*act)->der = NULL;

}

//---------------------------------------------------------------

v


