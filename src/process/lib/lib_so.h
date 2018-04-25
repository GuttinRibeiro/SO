#ifndef LIB_SO_H
#define LIB_SO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define N 10
#define LIMIT 10

//For create a new process
pid_t toGiveBirth(char *child, char **arg1, char **arg2);

//For manipulates files
int writeValues(char *filename, int *data);
int *getValues(char *filename);

#endif
