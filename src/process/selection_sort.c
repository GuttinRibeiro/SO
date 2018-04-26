#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {

  int *vector = getValues("data.txt");

  if(vector == NULL) {
    exit(-1);
  }

  int i, j, pivotPos, swap;

  for(i = 0; i < N-1; i++) {
    pivotPos = i;

    for(j = i+1; j < N; j++) {
      if(vector[j] > vector[pivotPos]) {
        pivotPos = j;
      }
    }

    if(vector[i] != vector[pivotPos]) {
      swap = vector[i];
      vector[i] = vector[pivotPos];
      vector[pivotPos] = swap;
    }
  }

  writeValues("data.txt", vector);
  free(vector);

  printf("Process %d finished!\n", getpid());
  exit(0);
}
