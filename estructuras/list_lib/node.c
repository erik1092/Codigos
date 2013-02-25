/**
  @file node.c
  @brief Codigo para el manejo de Nodos

  @author Erik Navarro
  @date 02/2013

*/

#include "../config.h"
#include "../debug.h"

#include "node.h"

#include <stdlib.h>
#include <stdbool.h>


struct Node * new_node(int value, struct Node *next) {
	struct Node *nodo;
	
	nodo = (struct Node *) calloc(1,sizeof(struct Node));
	if(nodo == NULL) {
		log_err("%s", "Can't allocate memory");
		return NULL;
	}
	
	log_debug("Nodo %i creado en la dirección %p apuntado a %p",value,nodo,next);
	
	nodo->value = value;
	nodo->next = next;
	
	return nodo;	
}

int destroy_nodo(struct Node *nodo) {
	int value;
	
	if(nodo == NULL) {
		log_err("%s", "Try to destroy null node");
		return -1;
	}
	
	log_debug("Nodo %i ubicado en %p destruido",nodo->value,nodo);
	value = nodo->value;
	free(nodo);
	
	return value;
}
