#include <stdio.h>
#include <stdlib.h>

int main()
{
   int z=3,a=5,c=8;

   if ((z < 5) && (a <= 5 || c > 0))
    printf("%d\n",z);

    char w;
    scanf("%c",&w);
    printf("%c\n",w);

    int b=-1;
    (a<b && b<c)? printf("estan ordenados"):printf("no estan ordenados");

    return 0;
}
