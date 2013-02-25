/**
  @file list.c
  @brief Codigo para el manejo de Listas

  @author Alvaro Parres
  @date 01/2013

*/

#include "../config.h"
#include "../debug.h"

#include "cola.h"
#include "node.h"

#include <stdlib.h>
#include <stdbool.h>

struct Node * get_node_before(struct COLA *cola, struct Node *node );

struct COLA * init_cola() {
	struct COLA *cola;
	
	cola = (struct COLA *) calloc(1,sizeof(struct COLA));
	if(cola == NULL) {
		log_err("%s", "Can't allocate memory");
		return NULL;
	}
	
	log_debug("Lista construida en la dirección %p",cola);
	
	
	cola->count = 0;
	cola->first = NULL;
	
	return cola;
}

int destroy_cola(struct COLA *cola) {
	
	struct Node *nodo;
	struct Node *nodo_to_drop;
	
	if(cola == NULL) {
		log_warn("%s","Try to destroy a NULL List");
		return false;
	}

    if(cola->count > 0 || cola->first != NULL) {
		nodo = cola->first;
		while(nodo->next != NULL) {
			nodo_to_drop = nodo;
			nodo = nodo->next;
			destroy_nodo(nodo_to_drop);
		}
		
		destroy_nodo(nodo);
    }

	log_debug("Lista en la dirección %p destruida",cola);	
	free(cola);
	return true;
}

void print_cola(struct COLA *cola) {
	struct Node *nodo;
	int count = 0;
	
	if(cola == NULL) {
		log_warn("%s","Try to print NULL list");
		return;
	}
	
	nodo = cola->first;
	do {
		printf("[%i]\t%i\n",count,nodo->value);
		nodo = nodo->next;
		count++;
	} while(nodo != NULL);
	
	return;
}


///////////////FIFO(fist-in/first-out)////

int insert_last(struct COLA *cola, int value) {
	
	struct Node *nodo;
	struct Node *centinela;
	
	int count = 0;
	
	if(lista == NULL) {
		log_warn("%s","Try to add node to NULL list");
		return -1;
	}
	
	nodo = new_node(value);
	if(nodo == NULL) {
		log_warn("%s","Cant create node");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(cola->count == 0) {
		log_debug("Nodo %i agregado al principio de la lista", value);
		cola->first = nodo;
		cola->count = 1;
		return 0;
	}
	
	if(cola->first == NULL) {
		log_err("Lista dice contener %i nodos pero sus nodos estan perdidos",cola->count);
		log_debug("Nodo %i agregado al principio de la lista", value);
		cola->first = nodo;
		cola->count = 1;
		return 0;
	}
	
	//La lista no esta vacia por lo tanto recorremos la lista.
	centinela = cola->first;
	count = 1;
	while(centinela->next != NULL) {
		centinela = centinela->next;
		count++;
	}
	if(count != cola->count) {
		log_err("La lista dice tener %i nodos pero se encontraro %i nodos",cola->count,count);
	}
	
	log_debug("Nodo %i agregado en la posición %i de la lista", value,count+1);
	centinela->next = nodo;
	cola->count = count+1;

	return count;
}

/////////////////
int remove_first(struct COLA *cola) {

	struct Node *centinela;
	
	int value;
	
	if(cola == NULL) {
		log_warn("%s","Try to remode node from a NULL list");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(cola->count == 0 || cola->first == NULL) {
		log_debug("%s","Lista vacia");
		return -1;
	}
	
	centinela = cola->first;
	cola->first = centinela->next;
	cola->count--;
	
	value = centinela->value;
	
	destroy_nodo(centinela);
	
	return value;
}


