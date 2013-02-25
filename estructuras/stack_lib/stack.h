/**
  @file stack.h
  @brief Definiciones y Prototipos para el manejo de pilas.

  @author Erik Navarro
  @date 02/2013

*/
#ifndef _STACK_H
#define _STACK_H

/** Estructura para el manejo de Pilas(stack) */
struct Stack {
	/** Cantidad de elementos que la pila tiene */
	int count;
	/** Apuntador al primer nodo de la pila*/
	struct Node *first;
};

//Prototipos
//Funciones Generales
struct Stack * init_stack();
int destroy_stack(struct Stack *pila);
void print_stack(struct Stack *pila);

//Funciones propias de la pila
int insert_last(struct Stack *pila, int value); 
int remove_last(struct Stack *pila);
struct Node * get_last_node(struct Stack *stack);
#endif
