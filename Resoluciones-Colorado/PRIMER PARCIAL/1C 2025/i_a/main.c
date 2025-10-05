#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

typedef struct nodito{
    char fecha[11];
    float precio_unitario,cant_comprada;
    struct nodito *sig;
}nodito;
typedef nodito *SubLista;

typedef struct nodo{
    char cod_barra[16];
    float precio_unitario,stock,ganancia;
    SubLista *sub;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

typedef struct nodoD{
    char cod_barra[16];
    float stock;
    struct nodoD *ant,*sig;
}nodoD;
typedef nodoD *PnodoD;
typedef struct{
    PnodoD pri,ult;
}TListaD;

int main()
{
    TCola C;
    TLista LS;
    TListaD LD;
    return 0;
}

