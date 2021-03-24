#ifndef __DFT_H
#define __DFT_H

#include "dft_hash.h"

#define SIZE_A 10

typedef struct {
    int id;
    int in_count;
} DFT_A_t;

int init_table(void);

#define SYS_DFT_new_activation 336
#define SYS_DFT_show 337
// #define SYS_DFT_hput 338
// #define SYS_DFT_hget 339
// #define SYS_DFT_delete 340


int DFT_new_activation(const struct pt_regs *regs);
int DFT_sub_activation(const struct pt_regs *regs);
// int DFT_hput(const struct pt_regs *regs);
// int DFT_hget(const struct pt_regs *regs);
// int DFT_delete(const struct pt_regs *regs);
int DFT_show(void);


#endif //__DFT_H
