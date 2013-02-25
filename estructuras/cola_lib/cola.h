/**
  @file cola.h
  @brief Defines y Prototipos para el manejo de colas.

  @author Erik Navarro
  @date 02/2013

*/
#ifndef _COLA_H
#define _COLA_H

/** Estructura para el manejo de Colas */
struct COLA {
	/** Cantidad de elementos que tiene la cola*/
	int count;
	/** Apuntador al primer nodo de la cola */
	struct Node *first;
};

//Prototipos
//Funciones Generales
struct COLA * init_cola();
int destroy_cola(struct COLA *cola);
void print_cola(struct COLA *cola);

//Funciones propias de las Colas

int insert_last(struct COLA *cola, int value); 
int remove_first(struct COLA *cola);
struct Node * get_last_node(struct COLA *Cola);
struct Node * get_first_node(struct COLA *Cola);
#endif
