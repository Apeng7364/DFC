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
    int task_id;
    int next_data;
} DFT_D_t;

int init_table(void);

#define SYS_DFT_alloc 335
#define SYS_DFT_new_activation 336
#define SYS_DFT_new_data 337

int DFT_alloc(void);
int DFT_new_activation(void *addr, size_t size, int next_data);
int DFT_new_data(int in_count, int in_data, int pid);

#endif //__DFT_H
