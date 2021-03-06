#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include "dft.h"
#include "dft_hash.h"

DFT_A_t DFT_A[SIZE_A];

int get_invalid_A(void);

int init_table() {
    int i;
    for (i = 0; i < SIZE_A; i++)
    {
        DFT_A[i].id = i;
        DFT_A[i].in_count = 0;
    }
    printk("init dft talbe\n");
    return 0;
}

int get_invalid_A() {
    int i = 0;
    while(DFT_A[i].in_count && i < SIZE_A) i++;
    if (i == SIZE_A) return -1;
    else return i;
}

int DFT_new_activation(const struct pt_regs *regs) {
    int i, in_count;
    i = get_invalid_A(); // 分配一个DFT行
    if (i == -1) return -1;
    // void *FN = regs->si;
    // hasht_put(FN, in_count);
    in_count = regs->di & 0xfffffffu;
    DFT_A[i].in_count = in_count;
    return i;
}

int DFT_sub_activation(const struct pt_regs *regs) {
    int i = regs->di & 0xffffffffu;
    DFT_A[i].in_count -= 1;
    return DFT_A[i].in_count;
}

int DFT_show() {
    int i;
    printk("%8s %8s\n", "NO", "COUNT");
    for (i = 0; i < SIZE_A; i++) {
        printk("%8d %8d\n", DFT_A[i].id, DFT_A[i].in_count);
    }
    printk("show hash\n");
    show_hash();
    return 0;
}


// int DFT_hput(const struct pt_regs *regs) {
//     return hasht_put((void *)regs->di, (int)(regs->si & 0xffffffffu));
// }
// int DFT_hget(const struct pt_regs *regs) {
//     return hasht_get((void *)regs->di);
// }

// int DFT_delete(const struct pt_regs *regs) {
//     return hasht_delete((void *)regs->di);
// }