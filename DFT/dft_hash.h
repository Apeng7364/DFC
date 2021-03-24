#ifndef __DFT_HASH_H
#define __DFT_HASH_H

#define SIZE_HASHT 11
struct DFT_H;
typedef struct DFT_H DFT_H_t;

struct DFT_H {
    // pid_t pid;
    int aid;
    void *addr;
    DFT_H_t *next;
    DFT_H_t *prev;
} ;

int init_hash_table(void);
void show_hash(void);
int hasht_put(void *addr, int aid);
int hasht_get(void *addr);
int hasht_delete(void *addr);
void destroy_hash_table(void);
#endif