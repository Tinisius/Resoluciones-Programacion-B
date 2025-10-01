#include "pilad.h"
#include <stdlib.h>
void IniciaP(TPila *P) {
*P = NULL;
}

void poneP(TPila *P, TElementoP x) {
 TPila N;
 N = (TPila)malloc(sizeof(nodop));
 N->car = x;
 N->sig = *P;
 *P=N;
}

TElementoP consultaP(TPila P) {
if (P) // if (P != NULL)
 return P->car;
}
