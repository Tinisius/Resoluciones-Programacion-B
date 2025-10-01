typedef struct {
    int h,m,s;
}THora;

THora crearHora(int horas,int minutos,int segundos);
THora deSegundosAHoras(int seg);
THora sumar(THora hora1, THora hora2);
THora suma(THora hora, int segundos);
int obtenerHora(THora hora);
int obtenerMinuto(THora hora);
int obtenerSegundo(THora hora);
