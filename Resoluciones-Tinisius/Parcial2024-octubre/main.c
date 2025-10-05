#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

typedef struct{
    int horas, minutos;
}Ttiempo;

typedef struct nodito{
    char pat[8];
    int fecha;
    char hora[6];
    Ttiempo Tabonado;
    Ttiempo Treal;
    struct nodito *sig;
}nodito;
typedef nodito *sublista;       //defino un tipo (al pedo pero bue)

typedef struct nodoD{
    char cod[6];
    char nom_ap[31];
    char estudia[2];
    sublista sub;
}nodo;
typedef Pnodo *nodo;            //defino un tipo (al pedo pero bue)

typedef struct{
    Pnodo pri, ult;
}TlistaD;

void IncisoA(TlistaD LD, Tcola C);

void actualizaLD(TlistaD LD, TelementoC rel);

//_________________________________________________
int main()
{
    TlistaD LD;
    Tcola C;
    cargaLD(&LD);
    cargaC(&C);

    IncisoA(&LD, &C);

    return 0;
}
//_________________________________________________

void IncisoA(TlistaD *LD, Tcola *C){
    TelementoC rel, centinela;
    poneC(C, centinela);
    sacaC(C,rel);
    while (rel.pat != centinela.pat){
        if (rel.pagado < rel.ocupado && 243 < rel.FechaMulta && rel.FechaMulta< 273)        //si es multa y es en septiembre
            actualizaLD(LD, rel);
        else
            poneC(C, rel);
        sacaC(C,rel);
    }
}

void actualizaLD(TlistaD LD, TelementoC rel){
    Pnodo act = *LD;
    sublista actS, antS, N;
    while (strcmp(act->cod, rel.cod) > 0)  //busca el agente, al encontrar corta (no se pasa de largo)
        act = act->sig;

    actS = act->sub;
    while (actS != NULL && srtcmp(actS->pat, rel->pat) < 0){     //busca la patente, asumo ordenada ascendente
        antS = actS;
        actS = actS->sig;
    }

    N = (sublista)malloc(sizeof(nodito));
    N->pat = rel.pat;
    N->fecha = rel.fechaMulta;                    //
    N->hora = rel.horaMulta;                    //
    N->Tabonado.horas = rel.pagado/60;        ////cargo el nodito auxiliar
    N->Tabonado.minutos = rel.pagado%60;        //
    N->Treal.horas = rel.ocupado/60;              //
    N->Treal.minutos = rel.ocupado%60;

    if (actS == act->sub){       //inserta al principio
        act->sub = N;
        N->sig = actS;
    }
    else{                //inserta al medio o al final
        antS->sig = N;
        N->sig = actS;
    }

}









