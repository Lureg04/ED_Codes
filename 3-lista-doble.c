#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicion de tipo de datos */
typedef struct s_persona{
    char nombre[50];
} PERSONA;

typedef struct s_nodo{
    PERSONA p;
    struct s_nodo *siguiente, *anterior;
} *NODO;

typedef struct s_lista{
    NODO primero;
    int total;
} LISTA;

/**
 * @brief Crea una lista vacia
 * 
 * @return LISTA lista vacia
 */
LISTA crearLista(){
    LISTA nueva;
    nueva.primero = NULL;
    nueva.total = 0;
    return nueva;
}

/**
 * @brief Crea un nodo para almacenar a la persona
 *
 * @param p persona a agregar al nodo 
 * @return NODO, puntero al nodo
 */
NODO crearNodo(PERSONA p){
    NODO nuevo = (NODO) malloc(sizeof(struct s_nodo));
    nuevo->p = p;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

/**
 * @brief Crea una persona
 * 
 * @param nombre puntero a la cadena de caracteres que 
 * representa el nombre
 * @return PERSONA 
 */
PERSONA creaPersona(char *nombre){
    PERSONA nueva;
    strcpy(nueva.nombre, nombre);
    return nueva;
}

/**
 * @brief Agrega una persona al final de la lista
 * 
 * @param lst, lista de personas
 * @param p, nueva eprsona a agregar 
 * @return LISTA, nueva lista con el nuevo elemento 
 */
LISTA agregarPersona(LISTA lst, PERSONA p){
    NODO aux, nuevo = crearNodo(p);
    /* Verifica si la lista esta vacia */
    if (lst.primero == NULL){
        lst.primero = nuevo;
        lst.total += 1;
    }
    else{
        /* Ubica el último elemento de la lista */
        aux = lst.primero;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        /* Conecta el nuevo nodo */
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
        lst.total += 1;
    }
    return lst;
}

/**
 * @brief Muestra el contenido de la lista
 * 
 * @param lst, lista de personas a imprimir
 */
void verLista(LISTA lst){
    NODO aux = lst.primero;
    printf("[ ");
    while (aux != NULL){
        printf("%s, ", aux->p.nombre);
        aux = aux->siguiente;
    }
    printf("]\n");
}

/**
 * @brief Muestra la lista recorriendo de derecha a izquierda
 * 
 * @param lst, lista de personas a mostrar
 */
void verListaInvertida(LISTA lst){
    NODO aux = lst.primero;
    printf("[ ");
    while (aux->siguiente != NULL){
        aux = aux->siguiente;
    }
    while(aux != NULL){
        printf("%s, ", aux->p.nombre);
        aux = aux->anterior;
    }
    printf("]\n");
}

/**
 * @brief Funcion principal
 * 
 * @return int 
 */
int main(){
    /* Crea la lista vacia */
    LISTA lista = crearLista();
    /* Agrega 3 personas a la lista */
    lista = agregarPersona(lista, creaPersona("Anastasia"));
    lista = agregarPersona(lista, creaPersona("Pericles"));
    lista = agregarPersona(lista, creaPersona("Aristoteles"));
    /* Muestra la lista de izquerda a derecha */
    verLista(lista);
    /* Muestra la lista de derecha a izquierda */
    verListaInvertida(lista);
    return 0;
}