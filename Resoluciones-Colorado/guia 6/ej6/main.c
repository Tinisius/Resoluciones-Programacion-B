#include <stdio.h>
#include <stdlib.h>

typedef struct tjugador{
    char jugador[15],estado;
    int edad;
    struct tjugador *sig;
}tjugador;

typedef struct tequipo{
    char equipo[12];
    int puntos;
    tjugador *jugadores;
    struct tequipo *sig;
}tequipo;
typedef tequipo *tlista;

void grabar_lista(tlista *L);
void addnodo(tlista *L, tequipo e, tlista *ult);
void addnodito(tlista L, tjugador e, tjugador **ult);

int main()
{
    tlista L = NULL;
    grabar_lista(&L);
    return 0;
}


grabar_lista(tlista *L){
    FILE * arch;
    tequipo equipo;
    tjugador jugador, *ult;
    int i,N;

    arch=fopen("equipos_jugadores.txt","r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo.\n");
    else{
        while (fscanf(arch,"%12s %d %d",equipo.equipo,&equipo.puntos,&N) == 3){
            equipo.jugadores = NULL;
            addnodo(L,equipo,&ult);
            for (i=0;i<N,i++){
                fscanf(archivo, "%15s %d %c\n", jugador.nombre, &jugador.edad, &jugador.estado);
                addnodito(ult, jugador, &Ult);
            }
        }
    }

}

void addnodo(tlista *L, tequipo e, tlista *ult)
{
    tlista aux = *ult, ant, nuevo;

    nuevo = (tlista)malloc(sizeof(tequipo));
    *nuevo = e;
    nuevo->sig = NULL;
    if (*L == NULL)
        *L = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

void addnodito(TLista L, TJugador e, TJugador **ult)
{
    TJugador *aux, *nuevo;
    aux = L->jugadores;
    nuevo = (TJugador *)malloc(sizeof(TJugador));
    *nuevo = e;
    nuevo->sig = NULL;
    if (aux == NULL)
        L->jugadores = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}
