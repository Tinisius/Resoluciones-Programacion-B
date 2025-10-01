typedef struct{
    int legajo,arribo,uso;
}TelemC;
typedef struct nodo{
    TelemC dato;
    struct nodo *sig;
}nodo;
typedef struct {
    nodo *pri,*ult;
}TCola;

void IniciaC(TCola *C);
int VaciaC(TCola C);
TelemC consultaC(TCola C);
void sacaC(TCola *C, TelemC *x);
void poneC(TCola *C, TelemC x);
