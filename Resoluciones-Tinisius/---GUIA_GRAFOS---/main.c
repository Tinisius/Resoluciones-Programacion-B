#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colasdin.h"
#define max 10

void P7a(int mat[][4], int n);
void P10a(int mat[][4], int n);

int main(){
    int n=4;
    int mat[4][4]={ {1,1,1,0},
                    {1,0,1,1},
                    {1,1,0,0},
                    {0,1,0,0} };
    //P7a(mat, n);

    P10a(mat, n);

    return 0;
}


void P7a(int mat[][4], int n){
    int v, i, gr=0;
    printf("ingrese V  \n");
    scanf(" %d", &v);

    for (i=0; i<n; i++){
        gr+=mat[v-1][i] != 0;
    }
    printf("%d", gr);
}


void P10a(int mat[][4], int n){
    int visitados[4], i, NodoIni=0, V;
    TCola C;
    for (i=0; i<4; i++)
        visitados[i]=0;
    IniciaC(&C);
    poneC(&C, NodoIni);
    visitados[NodoIni]=1;

    printf("recorido: \n");

    while (!vaciaC(C)){
        sacaC(&C, &V);      //nodo a visitar
        printf("%d ", V);   //lo muestro (visito)

        for (i=0; i<n; i++)    //recorro todos los vecinos de V
            if (mat[V][i]==1 && !visitados[i]){     //si esta conectado al vertice i Y no fue visitado
                visitados[i]=1;         //ahora i fue visi
                poneC(&C, i);           //lo pongo en la cola de pendientes a visitar
            }
        printf("\n");
    }
}
