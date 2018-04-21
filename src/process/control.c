#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define N 10
#define LIMIT 10

pid_t toGiveBirth(char *child, char **arg1, char **arg2) {
  pid_t child_pid;
  child_pid = fork();

  //Testing if this is the parent process
  if(child_pid != 0) {
    return child_pid;
  }

  execve(child, arg1, arg2);

  //If execve returned, something really bad happenend:
  exit(-1);
}

int main(int argc, char *argv[], char *envp[]) {

  //If this process was created by shell:
  if(getppid() == 6043) {
    srand(time(NULL));

    //FILE *fp = fopen(argv[1], "w");
    FILE *fp = fopen("augusto.txt", "w");

    int i;
    for(i = 0; i < N; i++) {
      fprintf(fp, "%d ", rand()%LIMIT);
    }

    fprintf(fp, "\n");
    fclose(fp);
  }

  pid_t inOrder_pid = toGiveBirth("bubble_sort", argv, envp);
  wait(&inOrder_pid);

  pid_t reverseOrder_pid = toGiveBirth("selection_sort", argv, envp);
  wait(&reverseOrder_pid);

  //printf("Control finished\n");
  exit(0);
}
