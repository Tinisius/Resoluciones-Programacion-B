#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "colas.h"

typedef struct nodito{
    char fecha[11];
    float Precio;
    float cant;
    struct nodito *sig;
}nodito;
//-----------------------
typedef struct nodoS{
    char codB[16];
    float precio;
    float stock;
    float margen;
    nodito *sub;
    struct nodoS *sig;
}nodoS;

typedef nodoS *TlistaS;
//-----------------------
typedef struct nodoD{
    char codB[16];
    float stock;
    struct nodoD *sig, *ant;
}nodoD;

typedef struct TlistaD{
    nodoD *pri, *ult;
}TlistaD;
//-----------------------




void incisoA(TlistaS *Productos, TlistaD *StockNeg, Tcola *CompraC);

void actualiza(TlistaS *Productos, TlistaD *StockNeg, TelementoC ElemComp);

void AgregaD(TlistaD *StockNeg, char codB[], float stock);

void incisoB(TlistaS *Productos, TlistaD *StockNeg);

void actuLS(TlistaS *Productos, TlistaD *StockNeg, char fecha[], char codB[], float cant, float precio);

void sacaD(TlistaD *StockNeg, char codB[]);

void InsertaSub(TlistaS nodoLS, char fecha[], float precio, float cant);

//______________________________________________________________________

int main()
{
    //TIPOS
    Tcola CompraC;
    TlistaS Productos;
    TlistaD StockNeg;


    cargarP(&Productos);         // <--
    cargarSN(&StockNeg);         //DEBERIA DESARROLLARLOS? NA
    cargarCompra(&CompraC);      // <--

    incisoA(&Productos, &StockNeg, &CompraC)

    incisoB(&Productos, &StockNeg)


    return 0;
}

//______________________________________________________________________

void incisoA(TlistaS *Productos, TlistaD *StockNeg, Tcola *CompraC, float){
    float total=0;
    float cantProd=0;
    TelementC ElemComp;

    while (!vaciaC(*CompraC)){
        sacaC(CompraC, ElemComp);
        actualiza(Productos, StockNeg, ElemComp, &total);
        cantProd += ElemComp.Cant;
    }

    printf("el total de la compra es: %f", total);
    printf("el prom por producto es: %f", total/cantProd);


}


void actualiza(TlistaS *Productos, TlistaD *StockNeg, TelementoC ElemComp, float *total){
    TlistaS aux=*Productos;
    while (strcmp(aux->codB, ElemComp.codB)<0){
        aux=aux->sig;
    }
    aux->stock -= ElemComp.cant;
    *total += ElemComp.cant * aux.precio;

    if (aux->stock < 0)
        AgregaD(StockNeg, aux->codB, aux->stock);
}


void AgregaD(TlistaD *StockNeg, char codB[], float stock){
    nodoD *N = (nodoD*) malloc(sizeof(nodoD));            //esta bien hacerlo en la misma sentencia

    strcpy(N->codB, codB)
    N->stock = stock;
    N->sig = NULL;

    if (StockNeg->pri == NULL){             //si la doble esta vacia
        StockNeg->pri = StockNeg->ult = N;
    }
    else{
        StockNeg->ult->sig = N;
        N->ant = StockNeg->ult;
        StockNeg->ult = N;
    }

}



void incisoB(TlistaS *Productos, TlistaD *StockNeg){
    FILE *arch = fopen("proveen.txt", "r");

    char fecha[11], codB[16];
    float cant, precio;

    if (arch != NULL){
        while (fscanf(arch, " %10s %15s %f %f", fecha, codB, cant, precio) == 4) //revisar si deberia ser 15s o 16s (cuenta el 0?)
            if (strcmp("2025/04/01", fecha)<=0 && strcmp("2025/04/30", fecha)>=0){
                actuLS(Productos, StockNeg, fecha, codB, cant, precio)
            }
    }
}


void actuLS(TlistaS *Productos, TlistaD *StockNeg, char fecha[], char codB[], float cant, float precio){
    TlistaS act =*Productos, ant, N;

    while (strcmp(act->codB, codB) < 0)
        ant = act
        act = act->sig;

    if (strcmp(act->codB, codB) == 0){      //si el producto existia (lo encotró) -> actualizo
        act->stock += cant;
        act->precio = (act->margen+100)/100 * precio;

        if (act->stock < cant && act->stock > 0){       //si antes era negativo y ahora es positivo -> borrar
            sacaD(StockNeg, act->codB);
        }
        InsertaSub(act, fecha, precio, cant)      //inserto la compra en la sublista de Act
    }
    else{                                    //si el producto no existia (se pasó de largo) -> lo inserto
        N = (TlistaS) malloc(sizeof(nodoS));
        N->codB = codB;
        N->precio = precio * 1.5;
        N->stock = cant;                    //inserto en el nuevo nodo de LS
        N->margen = 50;
        N->sig = act;
        if (act == *Productos)      //inserta al principio
            *productos = N;
        else
            ant->sig = N;
        InsertaSub(N, fecha, precio, cant)      //inserto la compra en la sublista de N

    }
}

void sacaD(TlistaD *StockNeg, char codB[]){
    nodoD aux = StockNeg->pri, del;

    while (aux != NULL){
        if (strcmp(aux->codB, codB) == 0){        // si encontré el codigo a borrar -> lo borro
            if (aux == StockNeg->pri){          //si es el primero
                del = aux;
                aux = aux->sig;
                StockNeg->pri = aux;
                aux->ant = NULL;
                free(del);
            }
            else if (aux == StockNeg->ult){     //si es el ultimo
                del = aux;
                aux = aux->sig;
                StockNeg->ult = del->ant;
                StockNeg->ult->sig = NULL;
                free(del);
            }
            else{                               //si esta por el medio
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                del = aux;
                aux = aux->sig;
                free(del);
            }
        }
    }
}


void InsertaSub(TlistaS nodoLS, char fecha[], float precio, float cant){
    nodito *N = (nodito) malloc(sizeof(nodito));
    N->cant = cant;
    strcpy(N->fecha, fecha);
    N->Precio =  precio;

    N->sig = nodoLS->sub;        //siempre inserto al principio, ni rrecorro
    nodoLS->sub = N;
}
