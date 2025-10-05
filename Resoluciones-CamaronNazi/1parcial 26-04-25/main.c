#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char dominio[8], fecha[9], hora[6];
    struct nodo * sig;}nodo;
typedef nodo * tlista;

typedef struct nodosub{
    char dominio[8];
    int cantobs;
    struct nodosub * sig;}nodosub;
typedef nodosub * tsublista;

typedef struct nodod{
    char puesto[4];
    tsublista automoviles;
    struct nodod * sig,* ant;}nodod;
typedef nodod * tlistad;
typedef struct{
    nodod * pri,* ult;}tlisdad;

void eliminar (tlista *lt, float *porcentaje);

int main(){
    tlista lt;
    tlistad pa;
    float porcentaje;
     eliminar(&lt,&porcentaje);
     if (porcentaje ==-1)
        printf("el porcentaje es 0 wachin");
     else
        printf("el porcentaje fue de %f",porcentaje);

 return 0;
}

void eliminar(tlista * lt, float * porcentaje){
    tlista aux = * lt, ant = NULL, borrar;
    int casostot,elim;
    elim=0;
    char mes1,mes2;
    while (aux!=NULL){
        casostot++;
        mes1=aux->fecha[4];
        mes2=aux->fecha[5];
        int largo = strlen(aux->dominio);
        char ultimoDigito = (largo == 6) ? aux->dominio[5] : aux->dominio[4];
        if (!(mes1=='1'&&(mes2=='1' || mes2=='2') || mes2==ultimoDigito)){
            elim++;
            borrar=aux;
            aux=aux->sig;
            if (ant==NULL)
                *lt=aux;
            else
                ant->sig=aux;
            free(borrar);
     }
        else{
            ant = aux;
            aux = aux->sig;
        }
    }

 *porcentaje = (casostot==0) ? -1:(float)elim/casostot*100;
}
