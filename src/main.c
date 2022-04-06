#include "matriz.h"

int main(){
    Matriz *m = malloc(sizeof(Matriz));
    
    IniciaM(m);
    PrintaM(m);
    PercorrerM(m);
    printf("\n");
    Caminho(m);
    printf("\nSOMA: %d\n", m->soma);
    return 0;
}