#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 3
#define SIZE sizeof(int)*N

int main() {
  int *smem = (int *)mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
  if(smem == MAP_FAILED) {
    return -1;
  }

  int *mem = (int *)malloc(SIZE);
  if(mem == NULL) {
    return -2;
  }

  int i;
  for(i = 0; i < N; i++) {
    smem[i] = i;
    mem[i] = i;
  }

  int pid = fork();
  if(pid < 0) {
    printf("Fork failed.\n");
  } else if(pid == 0) { /* Child proccess */
    printf("Child Proccess\n");

    for(i = 0; i < N; i++) {
      smem[i] = 2*i;
      mem[i] = 2*i;
    }

    printf("Shared Memory: ");
    for(i = 0; i < N; i++) {
      printf("%d ", smem[i]);
    }
    printf("\n");

    printf("Normal Memory: ");
    for(i = 0; i < N; i++) {
      printf("%d ", mem[i]);
    }
    printf("\n");
  } else {
    wait(NULL);
    printf("Father Proccess\n");

    printf("Shared Memory: ");
    for(i = 0; i < N; i++) {
      printf("%d ", smem[i]);
    }
    printf("\n");

    printf("Normal Memory: ");
    for(i = 0; i < N; i++) {
      printf("%d ", mem[i]);
    }
    printf("\n");
  }

  munmap(smem, SIZE);
  free(mem);

  return 0;
}
