#include "lib_so.h"

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

int writeValues(char *filename, int *data) {
  int file_descriptor = open(filename, O_WRONLY | O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  if(file_descriptor < 0) {
    return 1;
  }

  if(write(file_descriptor, data, N*sizeof(int)) != N*sizeof(int)) {
    return 1;
  }

  close(file_descriptor);
  return 0;
}

int *getValues(char *filename) {
  int *rtrn = (int *)malloc(N*sizeof(int));

  if(rtrn == NULL) {
    return NULL;
  }

  int file_descriptor = open(filename, O_RDONLY);

  if(file_descriptor < 0) {
    free(rtrn);
    return NULL;
  }

  if(read(file_descriptor, rtrn, N*sizeof(int)) != N*sizeof(int)) {
    free(rtrn);
    return NULL;
  }

  close(file_descriptor);

  return rtrn;
}
