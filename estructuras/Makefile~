#Makefile
#
# Instrucciones para compilar

NAME = estructuras
OBJS = main.o list_lib/list.o stack_lib/stack.o cola_lib/cola.o 
CC = g++
CFLAGS = -Wall -O2 -DDEBUG=4

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)
	rm -rf html

doc:
	doxygen
	


