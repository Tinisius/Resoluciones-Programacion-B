#include <stdio.h>
#include <stdlib.h>
#define DIM 100
int main()
{
    FILE * arch_nums;
    int *v[DIM]; // arreglo estatico con elementos punteros a enteros
    int num,i=0,j,n,m=6;
    int nums[]={10,-5,7,0,-2,15};

    //grabar archivo binario
    arch_nums=fopen("numeros.dat","wb");
    fwrite(nums,sizeof(int),6,arch_nums);
    fclose(arch_nums);
    //abrir archivo binario para lectura
    arch_nums=fopen("numeros.dat","rb");
    if (arch_nums==NULL){
        printf("Error al abrir el archivo");
        fclose(arch_nums);
        return 1;
    }

    while ((fread(&num, sizeof(int),1,arch_nums)== 1) && (i<DIM)){
        v[i] = (int*)malloc(sizeof(int));
        if (v[i]==NULL){
            printf("Error al asignar memoria");
            fclose(arch_nums);
            return 1;
        }
        *v[i]=num;
        i++;
    }
    fclose(arch_nums);

    //mostrar solo los positivos
    printf("Numeros positivos:\n");
    for (j = 0; j<i;j++){
        if (*v[j]>0)
            printf("%d\n",*v[j]);
    }

    //liberar memoria
    free(v);
    return 0;
}
