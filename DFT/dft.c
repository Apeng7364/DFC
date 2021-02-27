#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include "dft.h"

DFT_A_t DFT_A[size_A];
DFT_D_t DFT_D[size_D];

int init_table() {
    int i;
    for (i = 0; i < size_A; i++)
    {
        DFT_A[i].id = i;
        DFT_A[i].valid = 0;
        DFT_A[i].in_count = 0;
        DFT_A[i].in_data = 0;
        DFT_A[i].pid = 0;
    }
    
    for (i = 0; i < size_D; i++)
    {
        DFT_D[i].id = i;
        DFT_D[i].valid = 0;
        DFT_D[i].laddr_st = NULL;
        DFT_D[i].laddr_ed = NULL;
        DFT_D[i].task_id = 0;
        DFT_D[i].next_data = -1;
    }
    printk("init dft talbe\n");
    return 0;
}

int DFT_alloc() {
    printk("not implement.\n");
    return 0;
}

int get_invalid_A() {
    int i = 0; 
    while(DFT_A[i].valid && i < size_A) i++;
    return i;
}

int get_invalid_D() {
    int i = 0;
    while(DFT_D[i].valid && i < size_D) i++;
    return i;
}

int DFT_new_activation(void *addr, size_t size, int next_data) {
    int i = get_invalid_D();
    DFT_D[i].valid = 1;
    DFT_D[i].laddr_st = addr;
    DFT_D[i].laddr_ed = (void *)((unsigned long) addr + size);
    DFT_D[i].next_data = next_data;
}

int DFT_new_data(int in_count, int in_data, int pid) {
    int i = get_invalid_A();
    DFT_A[i].valid = 1;
    DFT_A[i].in_count = in_count;
    DFT_A[i].in_data = in_data;
    DFT_A[i].pid = pid;
}