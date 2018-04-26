#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {

  int *data = (int *)malloc(N*sizeof(int));

  if(data == NULL) {
    exit(-1);
  }

  srand(time(NULL));

  int i;
  for(i = 0; i < N; i++) {
    data[i] = rand()%LIMIT;
  }

  writeValues("data.txt", data);

  printf("Process %d finished!\n", getpid());
  exit(0);
}
