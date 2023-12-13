#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

#define LINEBUF 1024
#define ARGBUF  64
#define DELIMIT " \t\n"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *linked;

void push(int);
void pall();
void pint();
void pop ();

int check(char *order);
char **parse(char *line);
int excute(char **order);
void free_arr(char **arr);


#endif
