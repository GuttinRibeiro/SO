#include "lib/lib_so.h"

int main(int argc, char *argv[], char *envp[]) {

  pid_t inOrder_pid = toGiveBirth("bubble_sort", argv, envp);
  wait(&inOrder_pid);

  pid_t reverseOrder_pid = toGiveBirth("selection_sort", argv, envp);
  wait(&reverseOrder_pid);

  exit(0);
}
