#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

void borraElemP(TPila *P, TElemento x);

int main(){
    TPila P;
    TElementoP x;
    int cant=0;
    cargarP(*P);
    borraElemP(&P, x, cant);
    return 0;
}


void borraElemP(TPila *P, TElemento x, int *cant){
    TElementoP dato;
    if (!vaciaP(*P)){
        sacaP(P, dato);
        borraElemP(P, x, cant);
        if (dato == X)
            *cant++;
        else
            poneP(P, dato);
    }
}
///IMPLEMENTACION ESTATIICA
/*
//EN EL pilas.h

#include <stdlib.h>
#define MAX 100

typedef int TElementoP;
typedef struct{
    TElementoP dato[MAX];
    int tope;
}TPila;

void PoneP(TPila *P, TElementoP X);

void SacaP(TPila *P, TElementoP *X);

//EN EL pilas.c
#include "pilas.h"

void PoneP(TPila *P, TElementoP X){
    if (tope < MAX-1){
        P->dato[++P->tope] = X;
    }
}

void SacaP(TPila *P, TElementoP *X){
    if (P->tope != -1){
        *X = P->dato[P->tope--];
    }
}
*/














