#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include "dft_hash.h"
/*
 * 哈希表，由addr获取DFT行号
 */

DFT_H_t DFT_H[SIZE_HASHT];

int init_hash_table() {
    int i;
    for (i = 0; i < SIZE_HASHT; i++)
    {
        DFT_H[i].aid = 0;
        // DFT_H[i].pid = 0;
        DFT_H[i].next = NULL;
        DFT_H[i].prev = NULL;
        DFT_H[i].addr = NULL;
    }
    return 0;
}

void destroy_hash_table() {
    int i;
    DFT_H_t *p, *tmp;
    for (i = 0; i < SIZE_HASHT; i++) {
        p = &DFT_H[i];
        while (p->next) {
            tmp = p->next;
            p->next = p->next->next;
            vfree(tmp);
        }
    }
}

int hash(unsigned long a) {
    return a % SIZE_HASHT;
}

int hasht_put(void *addr, int aid) {
    int id;
    DFT_H_t *p;
    DFT_H_t *item = vmalloc(sizeof(DFT_H_t));
    id = hash((unsigned long) addr);
    p = &DFT_H[id];
    while (p->addr != addr && p->next) p = p->next;
    if (p->addr == addr) return -1;

    item->addr = addr;
    item->aid = aid;
    item->next = NULL;
    // item->pid = NULL;
    item->prev = p;
    p->next = item;
    return 0;
}

int hasht_get(void *addr) {
    int id;
    DFT_H_t *p;
    id = hash((unsigned long) addr);
    p = &DFT_H[id];
    while(p->addr != addr && p->next) p = p->next;
    if (p->addr == addr) return p->aid;
    return -1;
}

int hasht_delete(void *addr) {
    int id;
    DFT_H_t *p;
    id = hash((unsigned long) addr);
    p = &DFT_H[id];
    while(p->addr != addr && p->next) p = p->next;
    if (p->addr == addr) {
        if (p->next) p->next->prev = p->prev;
        p->prev->next = p->next;
        vfree(p);
        return 0;
    }
    return -1;
    
}

void show_hash() {
    int i;
    DFT_H_t *p;
    char *s = vmalloc(4096);
    printk("%8s %16s %8s\n", "NO", "ADDR", "AID");
    
    for (i = 0; i < SIZE_HASHT; i++) {
        memset(s, 0, 1024);
        sprintf(s, "%s%8d", s, i);
        p = &DFT_H[i];
        while (p->next) {
            p = p->next;
            sprintf(s, "%s%16lx %8d ", s, (unsigned long)p->addr, p->aid);
        }
        printk("%s\n", s);

    }
    vfree(s);
}
