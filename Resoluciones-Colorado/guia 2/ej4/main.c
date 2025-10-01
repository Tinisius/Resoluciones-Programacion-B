#include <stdio.h>
#include <stdlib.h>

void genV(float **p1);

int main()
{
    float *v;
    int i;
    genV(&v);
    for (i=0; i<=9; i++){
        if (*(v+i)>=0)
        printf("%5.2f \n", *(v+i));
    }
    free(v);
    return 0;
}

void genV(float **p1){
    int i;
    * p1 = (float*)malloc(10*sizeof(float));
    for(i=0;i<=9;i++)
        scanf("%f",&(*(*p1+i)));
}
