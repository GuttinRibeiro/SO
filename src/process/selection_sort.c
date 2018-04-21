#include <stdio.h>
#include <stdlib.h>

#define N 10

int * getValues(char *filename) {
  int *rtrn = (int *)malloc(N*sizeof(int));

  if(rtrn == NULL) {
    printf("Out of memory\n");
    exit(-1);
  }

  FILE *fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("ERROR\n");
    exit(-1);
  }

  int i;
  for(i = 0; i < N; i++) {
    fscanf(fp, "%d ", &rtrn[i]);
  }

  fclose(fp);

  return rtrn;
}

void writeValues(char *filename, int *data) {
  FILE *fp = fopen(filename, "w");

  if(fp == NULL) {
    printf("ERROR\n");
    exit(-1);
  }

  int i;
  for(i = 0; i < N; i++) {
    fprintf(fp, "%d ", data[i]);
  }
  fprintf(fp, "\n");

  fclose(fp);
}

int main(int argc, char *argv[], char *envp[]) {
  //int *vector = getValues(argv[1]);
  int *vector = getValues("augusto.txt");

  int i;
/*  for(i = 0; i < N; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");
*/
  int j, pivotPos, swap;

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

  //writeValues(argv[1], vector);
  writeValues("augusto.txt", vector);
  free(vector);
  //printf("Selection finished\n");

  exit(0);
}
