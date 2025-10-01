#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=1, n=2,z;
    int *p, *q; // p y q son punteros a enteros
    p = &m; // p recibe la dirección de m
    *p = 4; // sería incorrecto p=4; equivale m=4;
    printf("%d %p\n", *p, p); // contenido y la dirección de m
    q = &n; // q recibe la dirección de n
    z= *q; // equivale z = n;
    printf("%d %d\n", *p,);
    *p = &q;
    printf("%d %d\n", *p, *q);

    return 0;
}
