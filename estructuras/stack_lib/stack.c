/**
  @file stack.c
  @brief Codigo para el manejo de Pilas(stack)

  @author Erik Navarro
  @date 02/2013

*/

#include "../config.h"
#include "../debug.h"

#include "stack.h"
#include "node.h"

#include <stdlib.h>
#include <stdbool.h>


struct Node * get_node_before(struct Stack *pila, struct Node *node );


//// Crear Stack

struct Stack * init_stack() {
	struct Stack *pila;
	
	pila = (struct Stack *) calloc(1,sizeof(struct Stack));
	if(pila == NULL) {
		log_err("%s", "Can't allocate memory");
		return NULL;
	}
	
	log_debug("Lista construida en la dirección %p",lista);
	
	lista->count = 0;
	lista->first = NULL;
	
	return pila;
}

//// Destruir Pila

int destroy_stack(struct Stack *pila) {
	
	struct Node *nodo;
	struct Node *nodo_to_drop;
	
	if(pila == NULL) {
		log_warn("%s","Try to destroy a NULL List");
		return false;
	}

    if(pila->count > 0 || pila->first != NULL) {
		nodo = pila->first;
		while(nodo->next != NULL) {
			nodo_to_drop = nodo;
			nodo = nodo->next;
			destroy_nodo(nodo_to_drop);
		}
		
		destroy_nodo(nodo);
    }

	log_debug("Lista en la dirección %p destruida",pila);	
	free(pila);
	return true;
}

//// imprimir Pila

void print_Stack(struct Stack *pila) {
	struct Node *nodo;
	int count = 0;
	
	if(pila == NULL) {
		log_warn("%s","Try to print NULL list");
		return;
	}
	
	nodo = pila->first;
	do {
		printf("[%i]\t%i\n",count,nodo->value);
		nodo = nodo->next;
		count++;
	} while(nodo != NULL);
	
	return;
}
////////////////LIFO////////////
//// insertar al final de la pila

int insert_last(struct Stack *pila, int value) {
	
	struct Node *nodo;
	struct Node *centinela;
	
	int count = 0;
	
	if(pila == NULL) {
		log_warn("%s","Try to add node to NULL list");
		return -1;
	}
	
	nodo = new_node(value);
	if(nodo == NULL) {
		log_warn("%s","Cant create node");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(pila->count == 0) {
		log_debug("Nodo %i agregado al principio de la lista", value);
		pila->first = nodo;
		pila->count = 1;
		return 0;
	}
	
	if(pila->first == NULL) {
		log_err("Lista dice contener %i nodos pero sus nodos estan perdidos",pila->count);
		log_debug("Nodo %i agregado al principio de la lista", value);
		pila->first = nodo;
		pila->count = 1;
		return 0;
	}
	
//La lista no esta vacia por lo tanto recorremos la lista.
	centinela = pila->first;
	count = 1;
	while(centinela->next != NULL) {
		centinela = centinela->next;
		count++;
	}
	if(count != pila->count) {
		log_err("La lista dice tener %i nodos pero se encontraro %i nodos",lista->count,count);
	}
	
	log_debug("Nodo %i agregado en la posición %i de la lista", value,count+1);
	centinela->next = nodo;
	pila->count = count+1;

	return count;
}


//// Quitar el ultimo

int remove_last(struct Stack *pila) {

	struct Node *current;
	struct Node *last;
		
	int value;
	
	if(pila == NULL) {
		log_warn("%s","Try to remode node from a NULL list");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(pila->count == 0 || lista->first == NULL) {
		log_debug("%s","Lista vacia");
		return -1;
	}
	
	current = pila->first;
	last = NULL;
	while(current->next != NULL) {
		last = current;
		current = current->next;
	}

    if(last == NULL) {
		pila->first = NULL;
		pila->count = 0;		
	} else {
		last->next = NULL;
		lista->count--;
	}
	
	value = current->value;	
	destroy_nodo(current);
	
	return value;
}

struct Node * get_first_node(struct Stack *stack) {
    if(stack == NULL) {
		return NULL;
	}

	return stack->first;
}

struct Node * get_last_node(struct Stack *stack) {

	struct Node *node; 

	if(list == NULL || stack->first == NULL) {
		return NULL;
	}

	node = stack->first;
	while(node->next != NULL) {
		node = node->next;
	}
	
	return node;
}




