#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"


int main()
{
    tpila P;
    telemp x;
    FILE * caracter;
    caracter=fopen("caracteres.txt","r");
    if (caracter==NULL)
        printf("ERROR \n");
    else{
        iniciaP(&P);
       if (vaciaP(P)){
            while (fscanf(caracter, "%c", &x) == 1){
                poneP(&P,x);
                printf("tope: %c\n",consultaP(P));
            }
        }
        fclose(caracter);
    }

    return 0;
}

void iniciaP(tpila *P){
    (*P).tope=-1;
}

int vaciaP(tpila P){
    return (P.tope==-1);
}

void poneP(tpila *P,telemp x){
    if (((*P).tope)!=MAX-1)
        (*P).car[++((*P).tope)]=x;
}
telemp consultaP(tpila P){
    if (P.tope!=-1)
        return P.car[P.tope];
        return '\0';
}
