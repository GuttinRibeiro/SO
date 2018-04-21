#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

static char *buffer;

int main(int argc, char *argv[]) {
    int pagesize;
    pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1) {
      printf("Failed to get system memory alignment\n");
      return -1;
    }

    if( posix_memalign((void **)&buffer, pagesize,2*pagesize) ) {
      printf("Failed to allocate memory.\n");
      return -2;
    }

    buffer[0] = 1;
    printf("%d\n", buffer[0]);
    buffer[pagesize] = 2;
    printf("%d\n", buffer[pagesize]);

    /* protect the second part of buffer from be written */
    if (mprotect(buffer +pagesize, pagesize, PROT_READ) == -1) {
      return -1;
    }

    buffer[0] = 3;
    printf("%d\n", buffer[0]);

    buffer[pagesize] = 4;
    printf("%d\n", buffer[pagesize]);

    free(buffer);
    exit(EXIT_SUCCESS);
}
