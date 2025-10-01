#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void grabarvec(int v[MAX],int n);
void sumavec(int v[MAX],int n);
int main()
{
    int v[MAX],n;
    printf("ingrese el valor de n: "); scanf("%d",&n);
    grabarvec(v, n);
   sumavec(v, n);

    return 0;
}

void grabarvec(int v[MAX],int n){
    int i;
    for (i=0;i< n;i++)
        {
        printf("ingresar el valor %d del vector: ",i+1);
        scanf("%d",&v[i]);
    }

}

void sumavec(int v[MAX],int n){
    int i,suma=0;
    for (i=0;i< n;i++)
        suma+=v[i];
    printf("la suma de lo elementos da: %d\n",suma);
}
