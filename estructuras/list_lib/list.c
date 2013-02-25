/**
   @file list.c
   @brief Codigo para el manejo de Listas

   @autor Erik Navarro 
   @date 02/2013
*/

#include "../config.h"
#include "../debug.h"

#include "list.h"
#include "node.h"

#include <stdlib.h>
#include <stdbool.h>

struct Node * get_node_before(struct List *lista, struct Node *node );

struct List * init_list() {
	struct List *lista;
	
	lista = (struct List *) calloc(1,sizeof(struct List));
	if(lista == NULL) {
		log_err("%s", "Can't allocate memory");
		return NULL;
	}
	
	log_debug("Lista construida en la dirección %p",lista);
	
	// COMENTARIO PARA GENERAR UN CAMBIO EN EL ARCHIVO 
	
	lista->count = 0;
	lista->first = NULL;
	
	return lista;
}

int destroy_list(struct List *lista) {
	
	struct Node *nodo;
	struct Node *nodo_to_drop;
	
	if(lista == NULL) {
		log_warn("%s","Try to destroy a NULL List");
		return false;
	}

    if(lista->count > 0 || lista->first != NULL) {
		nodo = lista->first;
		while(nodo->next != NULL) {
			nodo_to_drop = nodo;
			nodo = nodo->next;
			destroy_nodo(nodo_to_drop);
		}
		
		destroy_nodo(nodo);
    }

	log_debug("Lista en la dirección %p destruida",lista);	
	free(lista);
	return true;
}

void print_list(struct List *lista) {
	struct Node *nodo;
	int count = 0;
	
	if(lista == NULL) {
		log_warn("%s","Try to print NULL list");
		return;
	}
	
	nodo = lista->first;
	do {
		printf("[%i]\t%i\n",count,nodo->value);
		nodo = nodo->next;
		count++;
	} while(nodo != NULL);
	
	return;
}

// Metodos para lista doblemente enlazada.

int insert_first(struct List *lista, int value) {
	
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
	if(lista->count == 0) {
		log_debug("Nodo %i agregado al principio de la lista", value);
		lista->first = nodo;
		lista->count = 1;
		return 0;
	}
	
	if(lista->first == NULL) {
		log_err("Lista dice contener %i nodos pero sus nodos estan perdidos",lista->count);
		log_debug("Nodo %i agregado al principio de la lista", value);
		lista->first = nodo;
		lista->count = 1;
		return 0;
	}
	
	//La lista no esta vacia por lo tanto respaldamos nodos.
	centinela = lista->first;
	lista->first = nodo;
	nodo->next = centinela; 	
	log_debug("Nodo %i agregado al principio de la lista", value);
	lista->count++;

	return count+1;
}

int insert_last(struct List *lista, int value) {
	
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
	if(lista->count == 0) {
		log_debug("Nodo %i agregado al principio de la lista", value);
		lista->first = nodo;
		lista->count = 1;
		return 0;
	}
	
	if(lista->first == NULL) {
		log_err("Lista dice contener %i nodos pero sus nodos estan perdidos",lista->count);
		log_debug("Nodo %i agregado al principio de la lista", value);
		lista->first = nodo;
		lista->count = 1;
		return 0;
	}
	
	//La lista no esta vacia por lo tanto recorremos la lista.
	centinela = lista->first;
	count = 1;
	while(centinela->next != NULL) {
		centinela = centinela->next;
		count++;
	}
	if(count != lista->count) {
		log_err("La lista dice tener %i nodos pero se encontraro %i nodos",lista->count,count);
	}
	
	log_debug("Nodo %i agregado en la posición %i de la lista", value,count+1);
	centinela->next = nodo;
	lista->count = count+1;

	return count;
}

int remove_first(struct List *lista) {

	struct Node *centinela;
	
	int value;
	
	if(lista == NULL) {
		log_warn("%s","Try to remode node from a NULL list");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(lista->count == 0 || lista->first == NULL) {
		log_debug("%s","Lista vacia");
		return -1;
	}
	
	centinela = lista->first;
	lista->first = centinela->next;
	lista->count--;
	
	value = centinela->value;
	
	destroy_nodo(centinela);
	
	return value;
}

int remove_last(struct List *lista) {

	struct Node *current;
	struct Node *last;
		
	int value;
	
	if(lista == NULL) {
		log_warn("%s","Try to remode node from a NULL list");
		return -1;
	}
	
	//Evaluamos si la lista contiene nodos;
	if(lista->count == 0 || lista->first == NULL) {
		log_debug("%s","Lista vacia");
		return -1;
	}
	
	current = lista->first;
	last = NULL;
	while(current->next != NULL) {
		last = current;
		current = current->next;
	}

    if(last == NULL) {
		lista->first = NULL;
		lista->count = 0;		
	} else {
		last->next = NULL;
		lista->count--;
	}
	
	value = current->value;	
	destroy_nodo(current);
	
	return value;
}

struct Node * get_first_node(struct List *list) {
    if(list == NULL) {
		return NULL;
	}

	return list->first;
}

struct Node * get_last_node(struct List *list) {

	struct Node *node; 

	if(list == NULL || list->first == NULL) {
		return NULL;
	}

	node = list->first;
	while(node->next != NULL) {
		node = node->next;
	}
	
	return node;
}


