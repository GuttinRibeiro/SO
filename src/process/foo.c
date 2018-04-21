#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t bar_pid;

  bar_pid = fork();
  if(bar_pid != 0) {
    printf("foo\n");
    exit(0);
  }

  execve("bar", argv, envp);

  exit(0);
}
