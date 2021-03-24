#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "dft.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    unsigned long addr, id = rand() % 10;
    if (argc > 1) addr = strtol(argv[1], NULL, 16);
    else addr = rand();
    syscall(SYS_DFT_hput, addr, id);
    syscall(SYS_DFT_show);
}