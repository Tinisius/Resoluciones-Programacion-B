#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//eliminar aux (RECUPERAR PILA CON RECURSIVIDAD)
void elim_recu(TPila *P,TelemP x,int *cant);

int main()
{
    TelemP x;
    TPila P;
    int cant;
    printf("ingrese un valor x");
    scanf("%d",&x);
    IniciaP(&P);
    Cargar(P);
    elim_recu(&P,&aux,&dato,x,&cant);

    printf("la cantidad de datos eliminados es %d",cant);
    return 0;
}

void elim_recu(TPila *P,TelemP x,int *cant){
    TelemP dato;
    if (VaciaP(P))
        *cant=0;
        else{
            sacaP(P,dato);
            elim_recu(P,x,cant);
            if (dato == x){
                (*cant)++;
            }
            else{
                poneP(P,dato);
            }
        }
}


