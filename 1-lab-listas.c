#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicion de tipo de datos */
typedef struct s_globo{
    char color[50];
} GLOBO;

typedef struct s_nodo{
    GLOBO g;
    struct s_nodo *siguiente;
} *NODO;

typedef struct s_lista{
    NODO primero;
    int total;
} LISTA;

/**
 * @brief Crea una lista vacia
 * 
 * @return lista vacia
 */
LISTA creaLista(){
    LISTA nueva;    
    nueva.primero = NULL;
    nueva.total = 0;    
    return nueva;
}

/**
 * @brief Agrega un nodo al final de la lista
 * 
 * @param lst lista a la cual se le agrega el nuevo nodo
 * @param nuevo nodo a agregar
 * @return LISTA nueva lista con el nuevo elemento
 */
LISTA agregarNodo(LISTA lst, NODO nuevo){
    NODO aux = lst.primero;
    /* Verifica si la lista esta vacia */
    if (aux == NULL){
        lst.primero = nuevo;
        lst.total += 1;
        return lst;
    }
    /* Ubica el ultimo nodo de la lista */
    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    /* Conecta el ultimo nodo con el nuevo */
    aux->siguiente = nuevo;
    /* Aumenta el total */
    lst.total += 1;
    return lst;
}

/**
 * @brief Muestra el listado de los globos
 * 
 * @param lst lista de globos a desplegar
 */
void verGlobos(LISTA lst){
    NODO aux = lst.primero;
    printf("Globos : { ");
    /* Recorre hasta el final de la lista */
    while(aux != NULL){
        printf("%s, ", aux->g.color);
        aux = aux->siguiente;
    }
    printf("}\n");
}

/**
 * @brief Crea nodo
 * 
 * @param nuevo_g Globo que se almacena 
 * @return NODO nodo con el nuevo elemento
 */
NODO crearNodo(GLOBO nuevo_g){
    NODO nuevo = (NODO) malloc(sizeof(struct s_nodo));
    nuevo->g = nuevo_g;
    nuevo->siguiente = NULL;
    return nuevo;
}

/* Funcion principal */
int main(){    
    LISTA lst = creaLista();    

    return 1;
}