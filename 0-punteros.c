#include <stdio.h>

int main(){
    int x, *px;
    char c, *pc;

    /* Asigna valores a las variables primitivas */
    x = 29;
    c = 'J';
    /* Obtiene la direccion de memoria de las variables */
    px = &x;
    pc = &c;

    /* Imprime el contenido de las direcciones ee memoria */
    printf("Contenido de px : %d\n", px);
    printf("Contenido de pc : %c\n", *pc);

}