#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {

  int *vector = getValues("data.txt");
  
  if(vector == NULL) {
    exit(-1);
  }

  int i, j, swap;
  for(j = N-1; j > 0; j--) {
    for(i = 0; i < j; i++) {
      if(vector[i] > vector[i+1]) {
        swap = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = swap;
      }
    }
  }

  writeValues("data.txt", vector);
  free(vector);

  printf("Process %d finished!\n", getpid());
  exit(0);
}
