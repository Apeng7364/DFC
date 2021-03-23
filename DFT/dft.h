#ifndef __DFT_H
#define __DFT_H

#define SIZE_A 10
#define SIZE_HASHT 65

typedef struct {
    int id;
    int in_count;
} DFT_A_t;

typedef struct {
    pid_t pid;
    int aid;
} DFT_H_t;

int init_table(void);
int init_hash_table(void);

#define SYS_DFT_new_activation 336
#define SYS_DFT_show 339

int DFT_new_activation(const struct pt_regs *regs);
int DFT_sub_activation(const struct pt_regs *regs);
int DFT_show(void);



#endif //__DFT_H
