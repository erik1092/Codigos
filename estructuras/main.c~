/**
@file main.c
@brief Archivo que contiene el MAIN del programa de listas

@autor Erik Navarro Rios
@date 02/2013

*/

#include "config.h"
#include "debug.h"
#include "list_lib/list.h"
#include "cola_lib/cola.h"
#include "stack_lib/stack.h"
/**
   @brief función Main del software.
   
   Función Main del Software.

   @param argc Cantidad de Argumentos recibidos.
   @param argv[] Arreglo de String con el valor de los argumentos.

   @return Regresa siempre 1 al terminar de correr el programa.
*/

int main(int argc, char *argv[]){

////////Lista
	struct List *list;
	int i;
	
	list = init_list();

	for(i=1; i<=10; i++){
		add(list,i);
	}

	print_list(list);

	destroy_list(list);

////////Cola
	struct COLA *Cola;
	int j;
	
	Cola = init_cola();

	for(j=1; j<=10; j++){
		add(Cola,j);
	}

	print_cola(Cola);

	destroy_cola(Cola);
	
	

////////Pila

	struct Stack *stack;
	int k;
	
	stack = init_stack();

	for(k=1; k<=10; k++){
		add(stack,k);
	}

	print_stack(stack);

	destroy_stack(stack);

	return 1;
}

