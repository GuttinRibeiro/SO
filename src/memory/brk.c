#include <unistd.h>
#include <stdio.h>

#define N 5
#define SIZE sizeof(int)*N

int main() {
  void *program_break = sbrk(0);
  printf("Data segment break: %p\n", program_break);

  int *vector = sbrk(SIZE);
  program_break = sbrk(0);
  printf("New Data segment break: %p\n", program_break);
  printf("Vector ptr: %p\n", vector);

  return 0;
}
