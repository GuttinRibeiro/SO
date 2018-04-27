#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
  if(n <= 2) {
    return 1;
  }

  return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, const char *argv[]) {
  int n = atoi(argv[1]);

  printf("Fibonacci de %d: %d\n", n, fibonacci(n));

  return 0;
}
