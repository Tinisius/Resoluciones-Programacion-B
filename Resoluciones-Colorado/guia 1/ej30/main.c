#include <stdio.h>
#include <stdlib.h>
#define DIM 100

typedef struct{
    char patente[7],fecha[16];
    int velo,velo_max;

}treg;

int main()
{
    FILE * datos;
    int n,i;
    treg reg;
    //grabar archivo txt
    datos=fopen("datos.txt","a");
    if (datos==NULL)
       printf("Error en la apertura. Es posible que el archivo no exista");
    else{
            printf("ingresar cantidad de datos: ");scanf("%d",&n);
            for (i=1;i<=n;i++){
                printf("\nRegistro %d:\n", i);

                printf("Ingrese patente (7 caracteres): ");
                scanf("%7s", reg.patente);

                printf("Ingrese fecha (dd/mm/aaaa hh:nn): ");
                scanf("%16s", reg.fecha);

                printf("Ingrese velocidad: ");
                scanf("%d", &reg.velo);

                printf("Ingrese velocidad maxima: ");
                scanf("%d", &reg.velo_max);
                fprintf(datos,"%s %d %d %s ",reg.patente,&reg.velo,&reg.velo_max,reg.fecha);
            }
        }
    fclose(datos);
    return 0;
}
