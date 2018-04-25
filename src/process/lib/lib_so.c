#include "lib_so.h"

pid_t toGiveBirth(char *child, char **arg1, char **arg2) {
  pid_t child_pid;
  child_pid = fork();

  //Testing if this is the parent process
  if(child_pid != 0) {
    return child_pid;
  }

  execve(child, arg1, arg2);

  //If execve returned, something really bad happenend:
  exit(-1);
}

int writeValues(char *filename, int *data) {
  FILE *fp = fopen(filename, "w");

  if(fp == NULL) {
    return 1;
  }

  int i;
  for(i = 0; i < N; i++) {
    fprintf(fp, "%d ", data[i]);
  }
  fprintf(fp, "\n");

  fclose(fp);
  return 0;
}

int *getValues(char *filename) {
  int *rtrn = (int *)malloc(N*sizeof(int));

  if(rtrn == NULL) {
    return NULL;
  }

  FILE *fp = fopen(filename, "r");

  if(fp == NULL) {
    return NULL;
  }

  int i;
  for(i = 0; i < N; i++) {
    fscanf(fp, "%d ", &rtrn[i]);
  }

  fclose(fp);

  return rtrn;
}
