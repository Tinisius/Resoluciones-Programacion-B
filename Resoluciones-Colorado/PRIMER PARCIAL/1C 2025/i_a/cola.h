#define MAX 50

typedef struct{
    char cod_barra[15];
    float cant_comprada;
}TelementosC

typedef struct {
    TelementosC nodo[MAX];
    int pri,ult;
}TCola;

void IniciaC (TCola *C);
int VaciaC (TCola C);
TelementosC consultaC (TCola C);
void sacaC (TCola *C, TElementosC* x);
void poneC (TCola *C, TElementosC x);

