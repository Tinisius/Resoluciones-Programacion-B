#include <stdio.h>
#include <stdlib.h>
#define DIM 100


int buscarBi(int A[],int *pri,int *ult,int *mid,int x);
int main()
{
    int n,A[DIM],x=9,m=9,pri=0,ult=9,mid;
    for (n=0;n<=m;n++)
        scanf("%d",&A[n]);
    mid=ult / 2;
    printf("%d",buscarBi(A,&pri,&ult,&mid,x));

    return 0;
}
int buscarBi(int A[],int *pri,int *ult,int *mid,int x){
    if (*pri>*ult)
        return -1;
    else
        if (x==A[*mid])
            return x;
        else
            if (x<A[*mid]){
                *ult=*mid-1;
                *mid=*ult/2;
                return buscarBi(A,pri,ult,mid,x);
            }
            else{
                *pri=*mid+1;
                *mid=(*pri+*ult)/2;
                return buscarBi(A,pri,ult,mid,x);
            }
}



