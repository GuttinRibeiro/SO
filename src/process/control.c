#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {

  pid_t fileGenerator_pid =  toGiveBirth("file_generator", argv, envp);
  printf("Process %d created!\n", fileGenerator_pid);
  wait(&fileGenerator_pid);

  pid_t inOrder_pid = toGiveBirth("bubble_sort", argv, envp);
  printf("Process %d created!\n", inOrder_pid);
  wait(&inOrder_pid);

  pid_t reverseOrder_pid = toGiveBirth("selection_sort", argv, envp);
  printf("Process %d created!\n", reverseOrder_pid);
  wait(&reverseOrder_pid);

  exit(0);
}
