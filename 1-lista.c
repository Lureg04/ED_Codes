#include <stdio.h>
#include <stdlib.h>

/* Definicion de tipo de datos */
typedef struct s_nodo{
    int numero;
    struct s_nodo *siguiente;
} *NODO;

/* Prototipo de las funciones */
NODO crearNodo(int valor){
    NODO nodo = (NODO) malloc(sizeof(struct s_nodo));
    /* Asigna valores a los elementos del nodo */
    nodo->numero = valor;
    nodo->siguiente = NULL;
    return nodo;
}

NODO agregaNodo(NODO lst, NODO nodo_nuevo){
    NODO auxiliar = lst; 
    /* Se ubica en el ultimo nodo de la lista */
    while (auxiliar->siguiente != NULL){
        auxiliar = auxiliar->siguiente;
    }
    /* Conecta el ultimo nodo con el nuevo */
    auxiliar->siguiente = nodo_nuevo;
    return lst;
}

void verNodos(NODO lst){
    NODO auxiliar = lst; 
    printf("[ ");
    while (auxiliar != NULL){
        /* Imprime el valor */
        printf("%d ", auxiliar->numero);
        /* Pasa al siguiente elemento */
        auxiliar = auxiliar->siguiente;
    }
    printf("]\n");
}

/* Funcion principal */
int main(){
    NODO raiz, nuevo;
    /* Crea el nodo raíz */
    raiz = (NODO) malloc(sizeof(struct s_nodo));
    /* Asigna valores a los elementos del nodo */
    raiz->numero = 29;
    raiz->siguiente = NULL;
    /* Agrega nodos a la lista */
    for(int i=10; i >= 1; i--){
        nuevo = crearNodo(i*2);
        raiz = agregaNodo(raiz, nuevo);
    }

    /* Muestra el contenido de la lista */
    verNodos(raiz);
    return 0;
}