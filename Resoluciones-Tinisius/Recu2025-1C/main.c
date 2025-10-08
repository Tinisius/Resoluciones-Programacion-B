#include <stdlib.h>
#include <stdio.h>
#include "pilas.h"

typedef struct NodoC{
    char RS[41];
    char prov[31];
    float com;
    struct NodoC *sig;
}NodoC;
typedef TlistaC *NodoC;

/*
typedef struct{
    char codMP[11];
    float com;
}TElementoP;
*/

typedef struct{
    char RS[41];
    float recB;
    float recN;
}regBin;

void incisoA(TlistaC *LC);

void buscaCC(TListaC *LC,TListaC *callCenter, RS);

float buscaCOM(Tpila *P, char codMP[], float *com);

void insertaCall(TListaC *LC, char RS[], char prov[], TListaC *callCenter);

void incisoB(TListaC *LC, char Q[]);

//________________________________________________________
int main(){
    Tlista LC;
    Tpila P;
    char Q[31];

    cargarLC(&LC);
    cargarP(&P);

    incisoA(&LC, &P);

    scanf("30s", Q);
    incisoB(&LC, Q);
    return 0;
}
//________________________________________________________

void incisoA(TlistaC *LC, TPila *P){
    FILE *ventas=fopen("VENTAS.txt", "rt"), *bin=fopen("COMXCC202505.dat", "ab");
    regBin Rtot;
    char RS[41], prov[31], codMP[11], fecha[20], cuit[14];
    float imp, com;
    TListaC callCenter;

    if (ventas!=NULL && bin!=NULL){     //Si se abrieron bien los archivos, procesa
        regBin.RS="";
        while (fscanf("%s %s %s %s %s %f", RS, prov, codMP, fecha, cuit, imp) == 6){ /// LA LECTURA SE HACE CON %S SIN INDICAR EL TAMAÑO CORTA EN EL ESPACIO (ASUMO '_')
            if (RS[strlen(RS)-1]=='A' && RS[strlen(RS)]=='R' && fecha[4]=='5' && fecha[8]=='2' && fecha[8]=='5'){
                if (strcmp(RS, regBin.RS) != 0){       //si cambió de callcenter

                    fwrite(&regBin, sizeof(regBin), 1, bin);    //escribo todos los datos y proceso el resto

                    buscaCC(LC, &callCenter, RS)
                    if (callCenter == NULL)     //si no existe en LC, la inserto
                        insertaCall(LC, RS, prov, &callCenter);
                    regBin.RS = RS;
                    regBin.recB = 0;
                    regBin.recN = 0;
                }
                //inserta los datos recien leidos
                buscaCOM(P, codMP, &com);
                regBin.recB += imp;
                regBin.recN = imp * (1-com) * (1-callCenter->com);
            }
        }
        fwrite(&regBin, sizeof(regBin), 1, bin);
        fclose(bin);
        fclose(ventas);
    }
}


void buscaCC(TListaC *LC,TListaC *callCenter, RS){
    TListaC act = *LC->sig;
    while (act!=*LC && strcmp(act->RS, RS)!=0)
        act = act->sig;
    if(strcmp(act->RS, RS) == 0)    //si lo encontró
        *callCenter = act;
    else
        *callCenter = NULL;
}


void buscaCOM(Tpila *P, char codMP[], float *com){
    tElementoP MP;
    if (!vaciaP(P)){
        sacaP(P, MP)
        if (strcmp(MP.codMP, codMP) == 0){      //si encontro el MP
            *com = MP.com;      //valor a devolver
            poneP(P, MP);
        }
        else{
            buscaCOM(P, codMP, &com);
            poneP(P, MP);           //insertamos a la vuelta
        }
    }
}


void insertaCall(TListaC *LC, char RS[], char prov[], TListaC *callCenter){
    *callCenter = (TLista) malloc(sizeof(NodoC));
    //inserto los datos en el nodo
    strcpy(*callCenter->RS, RS);
    strcpy(*callCenter->prov, prov);
    *callCenter->com = 0.045;
    //enlazo los punteros
    *callCenter->sig = *LC->sig    //el nuevo nodo ahora es el ultimo, apunta al pr
    *LC->sig = *callCenter;     //el previo ultimo elemento ahora apunta al nuevo nodo
    *LC = *callCenter;          //modifico la lista, apunta al nuevo ultimo
}


void incisoB(TListaC *LC, char Q[]){
    TListaC act=*LC->sig, ant=*LC;
    if (*LC){    //Si no esta vacia
        do{
            if (strcmp(act->prov, Q) == 0){     //eliminar
                if (*LC = *LC->sig){    //si hay 1 solo elemento
                    free(*LC);
                    *LC = NULL;
                }
                else{
                    if(act==*LC){   //elimina al final
                        act = act->sig;
                        ant->sig = act;
                        free(*LC);
                        *LC = ant;
                    }
                    else{        //elimina cualquiera
                        act = act->sig;
                        free(ant->sig);
                        ant->sig=act;
                    }
                }
            }
            else{
                ant = act;
                act = act->sig;
            }

        }while (*LC && act!=*LC->sig)   //hacer hasta que vacie la cola o llegue al final
    }
}
