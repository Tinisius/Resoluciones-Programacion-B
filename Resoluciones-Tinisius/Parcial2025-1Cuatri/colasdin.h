#ifndef pilasdin

typedef int TElementoC;
typedef struct nodo {
 TElementoC dato;
 struct nodo * sig;} nodo;
typedef struct {
nodo *pri, *ult;} TCola;

void IniciaC (TCola *C);
void poneC (TCola *C, TElementoC X);
void sacaC (TCola *C, TElementoC *X);
TElementoC consultaC (TCola C);
void poneC (TCola *C, TElementoC X);
void sacaC (TCola *C, TElementoC *X);
void colallena (TCola *C, TE)

#endif
