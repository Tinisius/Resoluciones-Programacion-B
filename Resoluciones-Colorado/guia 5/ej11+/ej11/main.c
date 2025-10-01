#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "tiempo.h"

void armarC(TCola *C);
void mostrar(TCola *C, float *prom,int *maxlegajo);
int main()
{
    TCola C;
    float prom;
    int maxlegajo;
    InciaC(&C);
    armarC(&C);
    mostrar(&C,&prom,&maxlegajo);
    printf("Tiempo promedio de espera: %5.2f\n", prom);
    printf("Legajo con mayor tiempo de espera: %d", maxlegajo);
    return 0;
}

void armarC(TCola *C){
    TelemC x;
    FILE * arch;
    arch = fopen("empleados_microondas.txt","r");
    if (arch==NULL)
        printf("Hubo un problema al abrir el archivo.\n");
    while (fscanf(arch,"%d %d %d",&x.legajo, &x.arribo, &x.uso)==3)
        poneC(C,x);
    fclose(arch);
}

void mostrar(TCola *C, float *prom,int *maxlegajo){
    TelemC x;
    int cont,acum, tespera, tinicio, tfin, maxespera;
    THora hinicial,hinicio,hfin;

    contador=acumulador=maxespera=tfin=0;
    hinicial=crearhora(12,0,0);

    printf("Legajo\tHora inicio\tHora final\n");
    while (!Vacia(*C)){
        sacaC(C,&x);
        if (tfin <= x.arribo){ //llego despues de q se liberara el horno
            tinicio = x.arribo;
            tespera = 0;
        }
        else{ //espera en la cola
            tinicio = tfin;
            tespera = tinicio - x.arribo;
        }
        if (tespera>=maxespera){
            maxespera = tespera;
            *maxlegajo = x.legajo;
        }
        tfin = tinicio + x.uso;
        cont++;
        acum += tespera;
        hinicio = suma(hinicial,tinicio);
        hfin = suma(hinicio,tfin);
        printf("%d\t %d:%d:%d\t %d:%d:%d\n", x.legajo, obtenerHora(hinicio), obtenerMinuto(hinicio), obtenerSegundo(hinicio), obtenerHora(hfin), obtenerMinuto(hfin), obtenerSegundo(hfin));
    }
    *prom = acum / cont;
}
