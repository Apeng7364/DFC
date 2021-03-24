#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "dft.h"

int main(int argc, char* argv[]) {
    // srand(time(0));
    unsigned long addr = strtol(argv[1], NULL, 16);
    int id = syscall(SYS_DFT_hget, addr);
    printf("get(%lx) = %d\n", addr, id);
    // syscall(SYS_DFT_show);
}