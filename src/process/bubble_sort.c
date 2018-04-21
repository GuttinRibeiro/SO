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
  int *vector = getValues(argv[1]);

  int i;
  for(i = 0; i < N; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  int j, swap;
  for(j = N-1; j > 0; j--) {
    for(i = 0; i < j; i++) {
      if(vector[i] > vector[i+1]) {
        swap = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = swap;
      }
    }
  }

  writeValues(argv[1], vector);
  free(vector);
  printf("Bubble finished\n");

  exit(0);
}
