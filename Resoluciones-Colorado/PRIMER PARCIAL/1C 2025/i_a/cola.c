#include "cola.h"

void IniciaC (TCola *C){
    (*C).pri = (*C).ult = -1;
}
int VaciaC (TCola C){
    return C.pri==-1;
}
TelementosC consultaC (TCola C){
    if (C.pri != -1)
        return C.TElementosC[C.pri];
}
void sacaC (TCola *C, TElementosC* x){
     if ((*C).pri != -1){
        *x = (*C).TelementosC[(*C).pri];
        if ((*C).pri == (*C).ult)
            IniciaC(C);
            else
                (*C).pri +=1;
     }
}
void poneC (TCola *C, TelementosC x){
     if ((*C).ult != MAX-1) {
        if ((*C).pri==-1)
            (*C).pri = 0;
        (*C).TelementosC[++((*C).ult)] = X;
 }

}
