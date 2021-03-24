#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/unistd.h>
#include <linux/time.h>
#include <linux/sched.h>
#include <linux/kallsyms.h>

#include "dft.h"

int clear_and_save_cr0(void);
int setback_cr0(void);
static int __init init_dft(void);
static void __exit exit_dft(void);

int orig_cr0;
unsigned long *syscall_table = 0;
static unsigned long orig_syscall[512];

int clear_and_save_cr0()	
{
   	unsigned int cr0 = 0;
   	asm volatile ("movq %%cr0, %%rax" : "=a"(cr0));
    orig_cr0 = cr0;
	cr0 &= 0xfffeffff; // write protect;
	asm volatile ("movq %%rax, %%cr0" :: "a"(cr0));
    return 0;
}

int setback_cr0() {
    asm volatile("movq %%rax, %%cr0" :: "a"(orig_cr0));
    return 0;
}

int init_dft() {
    printk("insert dft module.\n");
    syscall_table = (unsigned long *)kallsyms_lookup_name("sys_call_table");
    orig_syscall[SYS_DFT_new_activation] = (unsigned long)syscall_table[SYS_DFT_new_activation];
    orig_syscall[SYS_DFT_show] = (unsigned long)syscall_table[SYS_DFT_show];
    // orig_syscall[SYS_DFT_hput] = (unsigned long)syscall_table[SYS_DFT_hput];
    // orig_syscall[SYS_DFT_hget] = (unsigned long)syscall_table[SYS_DFT_hget];
    // orig_syscall[SYS_DFT_delete] = (unsigned long)syscall_table[SYS_DFT_delete];

    clear_and_save_cr0();
    syscall_table[SYS_DFT_new_activation] = (unsigned long)&DFT_new_activation;
    syscall_table[SYS_DFT_show] = (unsigned long)&DFT_show;
    // syscall_table[SYS_DFT_hput] = (unsigned long)&DFT_hput;
    // syscall_table[SYS_DFT_hget] = (unsigned long)&DFT_hget;
    // syscall_table[SYS_DFT_delete] = (unsigned long)&DFT_delete;
    setback_cr0();
    init_table();
    return 0;
}

void exit_dft() {
    printk("remove dft module.\n");
    clear_and_save_cr0();
    syscall_table[SYS_DFT_new_activation] = (unsigned long)syscall_table[SYS_DFT_new_activation];
    syscall_table[SYS_DFT_show] = (unsigned long)syscall_table[SYS_DFT_show];
    // syscall_table[SYS_DFT_hput] = (unsigned long)syscall_table[SYS_DFT_hput];
    // syscall_table[SYS_DFT_hget] = (unsigned long)syscall_table[SYS_DFT_hget];
    // syscall_table[SYS_DFT_delete] = (unsigned long)syscall_table[SYS_DFT_delete];
    setback_cr0();
    destroy_hash_table();
    DFT_show();
}

module_init(init_dft);
module_exit(exit_dft);
MODULE_LICENSE("GPL");
