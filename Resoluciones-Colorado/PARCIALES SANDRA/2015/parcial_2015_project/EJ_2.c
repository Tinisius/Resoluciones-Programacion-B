#include <stdio.h>
#include <stdlib.h>

typedef struct nodito{
    int Nro_Mesa,cant_comensales;
    struct nodito *sig;
}nodito;
typedef nodito *SubLista;

typedef struct nodo{
    char id_mozo[6];
    SubLista *sub;
    struct nodo *sig;
}nodo;
typedef nodo *Tlista;

int main()
{
    Tlista LS;
    cargarLS(&LS);
    return 0;
}
