#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t foo_pid;

  foo_pid = fork();
  if(foo_pid != 0) {
    printf("Main terminated\n");
    exit(0);
  }
  execve("foo", argv, envp);

  exit(0);
}
