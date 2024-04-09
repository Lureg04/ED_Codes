#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicion de tipo de datos */
typedef struct s_elemento{
    int numero;
    struct s_elemento *siguiente;
}*ELEMENTO;

typedef struct s_pila{
    ELEMENTO tope;
} PILA;

/// @brief Crea una pila vacia
/// @return pila vacia
PILA crearPila(){
    PILA nueva;
    nueva.tope = NULL;
    return nueva;
}

PILA push(PILA p, ELEMENTO nuevo){
    nuevo->siguiente = p.tope;
    p.tope = nuevo;   
    return p; 
}

/// @brief Determina si una pila esta vacia
/// @param p pila a analziar
/// @return 1 en caso de que sea vacia y 0 en caso contrario
int empty(PILA p){
    return p.tope == NULL;
} 

/// @brief Extrae el tope de la pila
/// @param p pila 
/// @return nueva pila considerando la extraccion del tope
PILA pop(PILA p){
    if (!empty(p)){
        p.tope = p.tope->siguiente;
    }    
    return p;
}


/// @brief Retorna el elemento que esta en el tope de la pila
/// @param p pila a procesar
/// @return elemento que se encuentra en el tope
ELEMENTO verTope(PILA p){
    return p.tope;
}


/// @brief Muestra el estadod el elemento
/// @param e elemento a procesar
void verElemento(ELEMENTO e){
    printf("{%d}\n", e->numero);
}

/// @brief Crea un elemento considerando el valor indicado
/// @param valor contenido a guardar en el elemento
/// @return elemento considerando el valor del parametro
ELEMENTO crearElemento(int valor){
    ELEMENTO e = (ELEMENTO) malloc(sizeof(struct s_elemento));
    e->numero = valor;
    e->siguiente = NULL;
    return e;
}

/* Funciones de desafio 
Estas funciones son versiones de push y pop aca implementadas
La idea es modificar de forma directa la pila que se pasa como parametro
Luego de implementarlas, debes probarla desde el main haciendo los cambios correspondientes
*/

void push(PILA *p, ELEMENTO nuevo){
    /* Escribe tu codigo aca */
}


void pop(PILA *p){
    /* Escribe tu codigo aca */
}

/* Funcion principal */
int main(){
    /* Crea la pila */
    PILA p = crearPila();
    /* Agrega elementos a la pila */
    for(int i=1; i <= 10; i++){
        printf("Agrega a la pila el valor %d\n", i);
        p = push(p, crearElemento(i));
    }
    /* Recorre la pila */
    while (!empty(p)){
        verElemento(verTope(p));
        p = pop(p);
    }
    return 0;
}