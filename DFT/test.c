#include <sys/syscall.h>
#include <unistd.h>
#include "dft.h"

int main() {
    syscall(SYS_DFT_alloc);
}