#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicion de tipo de datos */
typedef struct s_personaje{
    char nombre[50];
    int popularidad;
    struct s_personaje *siguiente;
} *PERSONAJE;

typedef struct s_lista{
    PERSONAJE primero;
    int total;
} LISTA;

/* Crea y retorna una lista vacia */
LISTA creaLista();
/* Crea y retorna un personaje */
PERSONAJE crear(char *nombre, int popularidad);
/* Agrega un personaje a la lista y retorna la lista */
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo);
/* Muestra los personajes registrados */
void verPersonajes(LISTA lista);
/* Elimina un personaje de la lista, dada la ubicacion x (partiendo desde 1) */
LISTA elimina(LISTA lst, int x);
/* Elimina un personaje, dado su nombre */
LISTA eliminaPorNombre(LISTA lst, char *victima);
/* Cambia el orden de 2 personajes, dadas sus ubicaciones X e Y (partiendo de 1) */
LISTA intercambio(LISTA lista, int x, int y);
/* Inserta los elementos de lst_b en la lst_a luego de la ubicacion x */
LISTA insertar(LISTA lst_a, LISTA lst_b, int x);
/* 
Genera una lista considerando todos los personajes de lst cuya 
popularidad se encuentre entre los valores minimo y maximo
*/
LISTA seleccion(LISTA lst, int minimo, int maximo);

/* Agrega un personaje a la lista */
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo){
    PERSONAJE auxiliar = lista.primero;
    /* Verifica si la lista se encuentra vacia */
    if (auxiliar == NULL){
        lista.primero = nuevo;
        lista.total += 1;
        return lista;
    }

    /* Verifica que el personaje sea unico */
    while(auxiliar != NULL){
        if (strcmp(auxiliar->nombre, nuevo->nombre) == 0){
            return lista;
        }
        auxiliar = auxiliar->siguiente;
    }
    /* Si llega a este punto entonces el personaje no esta registrado */
    auxiliar = lista.primero;
    while(auxiliar->siguiente != NULL){
        auxiliar = auxiliar->siguiente;
    }
    auxiliar->siguiente = nuevo;
    lista.total += 1;
    return lista;
}

/* Muestra los personajes registrados */
void verPersonajes(LISTA lista){
    PERSONAJE auxiliar = lista.primero;
    /* Verifica que la atraccion sea unica */
    printf("[ ");
    while(auxiliar != NULL){
        printf("%s, ", auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }
    printf("]\n");
}

/* Crea un personaje */
PERSONAJE crear(char *nombre, int popularidad){
    PERSONAJE nuevo;
    nuevo = (PERSONAJE) malloc(sizeof(struct s_personaje));
    strcpy(nuevo->nombre, nombre);
    nuevo->popularidad = popularidad;
    nuevo->siguiente = NULL;
    return nuevo;
}

/* Elimina un personaje, dada su ubicacion */
LISTA elimina(LISTA lst, int x){
    PERSONAJE aux = lst.primero, anterior = aux;
    for(int i=1; i< x; i++, anterior = aux, aux = aux->siguiente);
    /* Verifica si se trata del primer elemento */
    if (aux == anterior){
        lst.primero = lst.primero->siguiente;
        lst.total -= 1;        
    }
    else{
        anterior->siguiente = aux->siguiente;
        lst.total -= 1;        
    }
    return lst;
}

/* Elimina un personaje, dado su nombre */
LISTA eliminaPorNombre(LISTA lst, char *victima){
    PERSONAJE aux = lst.primero, anterior = aux;
    while(aux != NULL){
        /* Verifica que se trata del elemento */
        if (strcmp(aux->nombre, victima) == 0){
            /* Verifica si se trata del primer elemento */
            if (aux == anterior){
                lst.primero = lst.primero->siguiente;
                lst.total -= 1;
                return lst;
            }
            else{
                anterior->siguiente = aux->siguiente;
                lst.total -= 1;
                return lst;
            }
        }
        anterior = aux;
        aux = aux->siguiente;
    }
    return lst;
}

/* Crea y retorna una nueva lista intercambiando el orden de 2 personajes */
LISTA intercambio(LISTA lista, int x, int y){
    PERSONAJE x_nodo, y_nodo;
    LISTA r = creaLista();    
    /* Ubica el personaje de la posicion X */
    x_nodo = lista.primero;
    for(int i=1; i < x; i++, 
            r = agregaPersonaje(r, crear(x_nodo->nombre, x_nodo->popularidad)),
            x_nodo = x_nodo->siguiente);
    
    /* Ubica el personaje de la posicion Y */
    y_nodo = lista.primero;
    for(int i=1; i < y; i++, y_nodo = y_nodo->siguiente);
    //printf("Segundo elemento ubicado...%s\n", y_nodo->nombre);
    r = agregaPersonaje(r, crear(y_nodo->nombre, y_nodo->popularidad));
    /* Traspasa el resto de los elementos despues de x */
    while(x_nodo != NULL){
        if (x_nodo != y_nodo){
            r = agregaPersonaje(r, crear(x_nodo->nombre, x_nodo->popularidad));                    
        }
        x_nodo = x_nodo->siguiente;    
    }
    /* Traspasa el resto despues de y */
    while(y_nodo != NULL){
        r = agregaPersonaje(r, crear(y_nodo->nombre, y_nodo->popularidad));
        y_nodo = y_nodo->siguiente;            
    }    

    return r;

}

/* Crea una lista vacia */
LISTA creaLista(){
    LISTA nueva;
    
    nueva.primero = NULL;
    nueva.total = 0;
    
    return nueva;
}

/* Inserta una lista luego del nodo indicado */
LISTA insertar(LISTA lst, LISTA otra, int x){
    PERSONAJE x_nodo, y_nodo, pendiente;   
    LISTA resultado = creaLista(); 

    /* Ubica el personaje de la posicion X */
    x_nodo = lst.primero;
    for(int i=1; i <= x; i++, 
        resultado = agregaPersonaje(resultado, 
            crear(x_nodo->nombre, x_nodo->popularidad)),
        x_nodo = x_nodo->siguiente
        );
    
    pendiente = x_nodo;
    
    y_nodo = otra.primero;
    while (y_nodo != NULL){
        resultado = agregaPersonaje(resultado, 
            crear(y_nodo->nombre, y_nodo->popularidad));
        
        y_nodo = y_nodo->siguiente;
    }
    /* Inserta los pendientes que quedan */
    while (pendiente != NULL){
        resultado = agregaPersonaje(resultado, 
            crear(pendiente->nombre, pendiente->popularidad));
        pendiente = pendiente->siguiente;
    }
    return resultado;
}

/* Genera una lista considerando todos los personajes de lst*/
LISTA seleccion(LISTA lst, int minimo, int maximo){
    PERSONAJE aux = lst.primero;
    LISTA result = creaLista();
    while (aux != NULL){
        if (aux->popularidad >= minimo && aux->popularidad <= maximo){
            result = agregaPersonaje(result, 
                crear(aux->nombre, aux->popularidad));
        }
        aux = aux->siguiente;
    }
    return result;
}

/* Estructuras y funciones - PARTE 2 */
/* Definicion de tipo de datos */

typedef struct s_pila{
    PERSONAJE tope;
} PILA;

PILA crearPila(){
    PILA nueva;
    nueva.tope = NULL;
    return nueva;
}

void push(PILA *p, PERSONAJE nuevo){
    nuevo->siguiente = (*p).tope;
    (*p).tope = nuevo;    
}

int empty(PILA p){
    return p.tope == NULL;
} 

void pop(PILA *p){
    if ((*p).tope != NULL){
        (*p).tope = (*p).tope->siguiente;
    }    
}

PERSONAJE verTope(PILA p){
    return p.tope;
}

void verElemento(PERSONAJE e){
    printf("{%s tiene %d de popularidad}\n", e->nombre, e->popularidad);
}

/// @brief Retorna una pila con los mas populares
/// @param primera primera lista
/// @param segunda segunda lista
/// @return pila con los personajes mas populares 
PILA masPopulares(LISTA primera, LISTA segunda){
    PILA resultado = crearPila();
    PERSONAJE aux_corta, aux_larga, seleccionado;
    /* Compara el tamaño de las listas */
    if (primera.total > segunda.total){
        /* La primera lista es mas extensa, por tanto, ahi sobraran elementos */
        aux_corta = segunda.primero;
        aux_larga = primera.primero;
    }
    else{
        aux_corta = primera.primero;
        aux_larga = segunda.primero;
    }
    
    while(aux_corta != NULL){
        if (aux_corta->popularidad > aux_larga->popularidad){
            seleccionado = crear(aux_corta->nombre, aux_corta->popularidad);    
            push(&resultado, seleccionado);
        }
        else{
            seleccionado = crear(aux_corta->nombre, aux_corta->popularidad);    
            push(&resultado, seleccionado);
        }
        
        /* Avanza los punteros */
        aux_corta = aux_corta->siguiente;
        aux_larga = aux_larga->siguiente;
    }
    /* Procesa los elementos que quedan pendientes */
    if (primera.total > segunda.total){
        PERSONAJE mas_popular;
        int mayor = 0;
        while(aux_larga != NULL){
            if (aux_larga->popularidad > mayor){
                mas_popular = crear(aux_larga->nombre, aux_larga->popularidad);
            }
            aux_larga = aux_larga->siguiente;
        }
        push(&resultado, mas_popular);    
    }
    else{
        PERSONAJE menos_popular = crear(aux_larga->nombre, aux_larga->popularidad);
        int menor = aux_larga->popularidad;        
        while(aux_larga != NULL){
            if (aux_larga->popularidad < menor){
                menos_popular = crear(aux_larga->nombre, aux_larga->popularidad);
            }
            aux_larga = aux_larga->siguiente;
        }
        push(&resultado, menos_popular);          
    }
    return resultado;
}

/* Funcion principal */
int main(){
    LISTA lst_personajes = creaLista(), lst_otra = creaLista();
    /* Crea la primera lista */
    lst_personajes = agregaPersonaje(lst_personajes,
        crear("Iron Man", 10));
    lst_personajes = agregaPersonaje(lst_personajes,
        crear("Thanos", 8));
    /* Muestra la lista de personajes */
    printf("Lista 1\n----\n");
    verPersonajes(lst_personajes);
    /* Crea la segunda lista */
    lst_otra = agregaPersonaje(lst_otra,
        crear("Flash", 10));
    lst_otra = agregaPersonaje(lst_otra,
        crear("Thor", 7));
    lst_otra = agregaPersonaje(lst_otra,
        crear("Capitan America", 10));
    /* Muestra la lista de personajes */
    printf("Lista 2\n----\n");
    verPersonajes(lst_otra);   
    /* Muestra la lista final */     
    LISTA lst_final = insertar(lst_otra, lst_personajes, 1);
    printf("Lista Resultado\n----\n");
    verPersonajes(lst_final);   
    /* Muestra la lista de personajes originales para mostrar que se mantiene */
    printf("Lista 2\n----\n");
    verPersonajes(lst_otra);      
    printf("Lista 1\n----\n");
    verPersonajes(lst_personajes);   
    /* Intercambia elementos */
    printf("Prueba el intercambio...\n");
    lst_final = intercambio(lst_final, 2, 3);
    printf("Lista post intercambio\n----\n");
    verPersonajes(lst_final);      

    /* Selecciona por popularidad */   
    printf("Seleccion\n--\n");
    verPersonajes(seleccion(lst_final, 8,10));
    /* Elimina por indice */
    lst_final = elimina(lst_final, 3);
    printf("Lista post eliminacion por indice\n----\n");
    verPersonajes(lst_final);      

    /* Elimina por nombre */
    lst_final = eliminaPorNombre(lst_final, "Thor");
    printf("Lista post eliminacion por nombre\n----\n");
    verPersonajes(lst_final);      

    /* Prueba de la funcionalidad de la PARTE 2 */
    printf("\n\n -- PARTE 2 -- \n\n");
    printf("Lista 2 ...\n");
    verPersonajes(lst_personajes);
    printf("Lista 1 ...\n");
    verPersonajes(lst_otra);
    //PILA r = masPopulares(lst_personajes, lst_otra);
    PILA r = masPopulares(lst_otra, lst_personajes);
    while(!empty(r)){
        verElemento(verTope(r));
        pop(&r);
    }
    return 0;
}