#ifndef __DFT_H
#define __DFT_H

#define size_A 10
#define size_D 50

typedef struct {
    int id;
    int valid;
    int in_count;
    int in_data;
    int pid;
} DFT_A_t;

typedef struct {
    int id;
    int valid;
    void *laddr_st;
    void *laddr_ed;
    int aid;
    int next_data;
} DFT_D_t;

int init_table(void);

#define SYS_DFT_new_activation 336
#define SYS_DFT_new_data 337
#define SYS_DFT_init_data 338
#define SYS_DFT_show 339


int DFT_new_data(const struct pt_regs *regs);
int DFT_new_activation(const struct pt_regs *regs);
int DFT_init_data(const struct pt_regs *regs);
int DFT_show(void);



#endif //__DFT_H
