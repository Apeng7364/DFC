#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include "dft.h"
int get_invalid_A(void);
int get_invalid_D(void);

DFT_A_t DFT_A[size_A];
DFT_D_t DFT_D[size_D];

int init_table() {
    int i;
    for (i = 0; i < size_A; i++)
    {
        DFT_A[i].id = i;
        DFT_A[i].valid = 0;
        DFT_A[i].in_count = -1;
        DFT_A[i].in_data = -1;
        DFT_A[i].pid = -1;
    }
    
    for (i = 0; i < size_D; i++)
    {
        DFT_D[i].id = i;
        DFT_D[i].valid = 0;
        DFT_D[i].laddr_st = NULL;
        DFT_D[i].laddr_ed = NULL;
        DFT_D[i].aid = -1;
        DFT_D[i].next_data = -1;
    }
    printk("init dft talbe\n");
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

int DFT_new_data(const struct pt_regs *regs) {
    int i = get_invalid_D();
    void *addr = (void *)regs->di;
    size_t size = regs->si;
    int next_data = regs->dx & 0xffffffffu;
    DFT_D[i].valid = 1;
    DFT_D[i].laddr_st = addr;
    DFT_D[i].laddr_ed = (void *)((unsigned long) addr + size);
    DFT_D[i].next_data = next_data;
    return i;
}

int DFT_new_activation(const struct pt_regs *regs) {

    int i = get_invalid_A();
    int in_count = regs->di & 0xffffffffu;
    int in_data = regs->si & 0xfffffffu;
    int pid = regs->dx & 0xffffffffu;
    DFT_A[i].valid = 1;
    DFT_A[i].in_count = in_count;
    DFT_A[i].in_data = in_data;
    DFT_A[i].pid = pid;
    return i;
}

int DFT_init_data(const struct pt_regs *regs) {
    int item = regs->di & 0xffffffffu;
    int aid = regs->si & 0xffffffffu;
    int next = regs->dx & 0xffffffffu;
    DFT_D[item].next_data = next;
    DFT_D[item].aid = aid;
    return 0;
}






int DFT_show() {
    int i;
    printk("%8s %8s %8s %8s %8s\n", "NO", "VALID", "COUNT", "DATA", "PID");
    for (i = 0; i < size_A; i++) {
        printk("%8d %8d %8d %8d %8d\n", DFT_A[i].id, DFT_A[i].valid, DFT_A[i].in_count, DFT_A[i].in_data, DFT_A[i].pid);
    }
    printk("%8s %8s %25s %8s %8s\n", "NO", "VALID", "ADDR", "ACTIV", "NEXT");
    for (i = 0; i < size_D; i++) {
        printk("%8d %8d %012lX-%012lX %8d %8d\n", DFT_D[i].id, DFT_D[i].valid, (unsigned long)DFT_D[i].laddr_st, (unsigned long)DFT_D[i].laddr_ed, DFT_D[i].aid, DFT_D[i].next_data);
    }
    return 0;
}

