#include <stdio.h>
#include <stdlib.h>

/* Definicion de tipo de datos */
typedef struct s_nodo{
    int numero;
    struct s_nodo *siguiente;
} *NODO;

/* Funcion principal */
int main(){
    /* Crea el nodo */
    NODO nodo = (NODO) malloc(sizeof(struct s_nodo));
    /* Asigna valores a los elementos del nodo */
    nodo->numero = 29;
    nodo->siguiente = NULL;
    /* Accede a los elementos del nodo */
    printf("Valor del nodo %d\n", nodo->numero);

    return 0;
}