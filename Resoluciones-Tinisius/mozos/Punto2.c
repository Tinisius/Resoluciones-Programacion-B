#include <stdio.h>
#include <stdlib.h>

typedef struct Nodito{
    int NroM;
    int cantC;
    struct Nodito *sig;
}Nodito;
typedef Nodito *sublista;

typedef struct NodoS{
    char id[6];
    sublista sub;
    struct NodoS *sig;
}NodoS;
typedef NodoS *TListaS;

void cerrarM(TListaS *LS, char mozo[], int mesa);


int main(){
    char mozo[6];
    int mesa;
    TListaS LS;

    printf("ingrese id mozo");
    scanf("%5s", mozo);
    printf("ingrese nro mesa");
    scanf(" %d", mesa);

    cerrarM(&LS, mozo, mesa);

    return 0;
}


void cerrarM(TListaS *LS, char mozo[], int mesa){
    TListaS act=*LS, ant, elimMo;
    sublista actSub, antSub, elimMe;
    int MsinC, M1C;

    printf("listado mozos\n");
    printf("id mozo     mesas sin cerrar     mesas con 1com\n");
    while (act != NULL){  //itera todos los mozos
        MsinC = M1C = 0;
        actSub = act->sub;
        while (actSub != NULL){     //itera todas las mesas
            if (strcmp(act->id, mozo)==0 && actSub->NroM==mesa){  //si hay que eliminar la mesa
                elimMe = actSub;
                actSub = actSub->sig;
                if (elimMe == act->sub)
                    act->sub = actSub;
                else
                    antSub->sig = actSub;
                free(elimMe);
            }
            else{
                MsinC++;
                M1C += actSub->cantC == 1;
                antSub = actSub;
                actSub = actSub->sig;
            }
        }
        printf("%5s  %d  %d", act->id, MsinC, M1C);
        if (act->sub == NULL){  //si hay que eliminar el mozo
            elimMo = act;
            act = act->sig;
            if (elimMo == *LS)
                *LS = act;
            else
                ant->sig = act;
            free(elimMo)
        }
        else{
            ant = act;
            act = act->sig;
        }
    }
}
