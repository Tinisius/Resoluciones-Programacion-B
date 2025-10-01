#include <stdio.h>
#include <stdlib.h>

int main()
{
int *p, a = 4, b = 5;
p = &b;
*p *= 2;
printf("b=%d *p=%d\n", b, *p);
printf("&b=%p p=%p &p=%p\n", &b, p, &p);
b = *p *3;
printf("b=%d *p=%d\n", b, *p);
printf("&b=%p p=%p\n", &b, p);
    return 0;
}
