#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {
  //FILE *fp = fopen(argv[0], "w");
  FILE *fp;
  fp = fopen("data.txt", "w");

  if(fp == NULL) {
    exit(-1);
  }

  srand(time(NULL));

  int i;
  for(i = 0; i < N; i++) {
    fprintf(fp, "%d ", rand()%LIMIT);
  }

  fprintf(fp, "\n");
  fclose(fp);

  printf("Process %d finished!\n", getpid());
  return 0;
}
