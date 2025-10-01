#define MAX 50

typedef char telemp;

typedef struct{
    telemp car[MAX];
    int tope;}tpila;

void iniciaP(tpila *P);
int vaciaP(tpila P);
void poneP(tpila *P, telemp x);
telemp consultaP(tpila P);
