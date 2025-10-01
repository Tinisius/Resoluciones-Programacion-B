#include <stdio.h>
#include <stdlib.h>
#include "pilad.h"

int main()
{
    FILE * caracteres;
    TPila P;
    TElementoP x;
    caracteres = fopen("caracteres.txt","r");
    IniciaP(&P);
    while (fscanf(caracteres,"%c",&x)==1){
        poneP(&P,x);
        printf("%c",consultaP(P));
    }
    fclose(caracteres);
    free(P);
    return 0;
}
