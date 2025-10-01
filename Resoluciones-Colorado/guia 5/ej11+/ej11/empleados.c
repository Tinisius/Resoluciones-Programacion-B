#include <stdlib.h>
#include "empleados.h"

void InciaC (TCola *C){
     (*C).pri = (*C).ult = NULL;
}

int VaciaC(TCola C){
    return C.pri==NULL;
}

void poneC(TCola *C,TelemC x){
    nodo *aux;
    aux=(nodo *) malloc (sizeof(nodo));
    aux->dato=x;
    aux->sig=NULL;
    if (C->pri==NULL)
        C->pri=aux;
    else
        (*C).ult->sig=aux; //no entiendo esta parte, pq lo asigna dsp del ultimo
    C->ult=aux; // tengo los mismos datos en ult y ult->sig? pq
}

void sacaC(TCola *C,TelemC *x){
    nodo *aux;
    if (C->pri != NULL){
        aux=C->pri;
        *x = aux->dato;
        C->pri = (*C.pri->sig);
        if ((*C).pri == NULL)
            (*C).ult = NULL;
        free(aux);
    }
}

TelemC consultaC (TCola C){
    if (C.pri !=NULL)
        return C.pri-> dato;
}
