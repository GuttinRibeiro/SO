#ifndef LIB_SO_H
#define LIB_SO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define N 10
#define LIMIT 10

//Para criar um novo processo:
pid_t toGiveBirth(char *child, char **arg1, char **arg2);

//Para manipular o arquivo de dados:
int writeValues(char *filename, int *data);
int *getValues(char *filename);

#endif
