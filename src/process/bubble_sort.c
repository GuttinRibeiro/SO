#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {
  if(generateFile("augusto.txt")) {
    printf("Error! Generation of data file not completed.\n");
    exit(-1);
  }

  int *vector = getValues("augusto.txt");

  int i;
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

  writeValues("augusto.txt", vector);
  free(vector);

  exit(0);
}
