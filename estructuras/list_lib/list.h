/**
  @file list.h
  @brief Defines y Prototipos para el manejo de listas.

  @author Erik Navarro
  @date 02/2013

*/
#ifndef _LIST_H
#define _LIST_H

/** Estructura para el manejo de Listas */
struct List {
	/** Cantidad de elementos que la lista tiene */
	int count;
	/** Apuntador al primer nodo de la lista */
	struct Node *first;
};

//Prototipos
/**
   @brief Crea una nueva lista.
   
   @returns Regresa un apuntador hacia la nueva lista, regresa NULL en caso de error.
*/
struct List * init_list();

/**
   @brief Destruye una lista liberando la memoria.
   
   @param *lista apuntador a la lista a destruir.

   @returns regresa true o false segun sea el caso.
*/
int destroy_list(struct List *lista);

/**
   @brief Agrega un nuevo nodo a la lista.
   
   @param *lista Apuntador a la lista donde se agregara el elemento.
   @param value valor del nodo

   @returns regresa la posición del nodo o -1 en caso de error..
*/
int add(struct List *lista, int value) ;

/**
   @brief Imprime una lista
   
   @param *lista apuntador a la lista a imprimir.
*/
void print_list(struct List *lista);



//Funciones propias de la Lista
//void swap(struct List *lista);
int insert_first(struct List *lista, int value);
int insert_last(struct List *lista, int value); 
int remove_first(struct List *lista);
int remove_last(struct List *lista);
struct Node * get_last_node(struct List *list);
struct Node * get_first_node(struct List *list);



#endif
