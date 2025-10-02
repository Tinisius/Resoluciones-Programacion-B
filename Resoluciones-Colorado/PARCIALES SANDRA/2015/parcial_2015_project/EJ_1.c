#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void elim_recu(TPila *P,TPila *aux,TelemP *dato,TelemP x,int *cant);

int main()
{
    TelemP dato,x;
    TPila P,aux;
    int cant=0;
    printf("ingrese un valor x");
    scanf("%d",&x);
    IniciaP(&P);
    IniciaP(&aux);
    Cargar(P);
    elim_recu(&P,&aux,&dato,x,&cant);

    printf("la cantidad de datos eliminados es %d",cant);
    return 0;
}

void elim_recu(TPila *P,TPila *aux,TelemP *dato,TelemP x,int *cant){
    if (VaciaP(P))
        *cant=0;
        else{
            if (sacaP(P,dato) == x){
                elim_recu(&P,&aux,&dato,x,&cant);
                cant++;
            }
            else{
                poneP(aux,dato);
                elim_recu(&P,&aux,&dato,x,&cant);
            }
        }
    poneP(P,aux.dato);
}
