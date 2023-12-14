#ifndef FUNC_H
#define FUNC_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>


extern stack_t *linked;
extern int line;

int push(int);
int pall();
int pint();
int pop ();
int swap();
int add();
int sub();
int divi();
int mul();

int pchar();

int check(char *order);
char **parse(char *line);
int excute(char **order);
void free_arr(char **arr);
void free_linked(void);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
