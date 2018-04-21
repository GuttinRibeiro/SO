#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define N 10

int main(int argc, char *argv[], char *envp[]) {
  printf("%s\n", argv[1]);


  int *vector = (int *)malloc(N*sizeof(int));

  FILE *fp = fopen(argv[1], "r");

  int i;
  for(i = 0; i < N; i++) {
    fscanf(fp, "%d ", &vector[i]);
  }

  fclose(fp);

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

  printf("Bubble finished\n");

  fp = fopen(argv[1], "w");

  for(i = 0; i < N; i++) {
    fprintf(fp, "%d ", vector[i]);
  }

  fclose(fp);

  exit(0);
}
