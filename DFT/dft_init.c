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
unsigned long orig_syscall[512];
static int (*orig_DFT_alloc)(void);

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

int __init init_dft() {
    printk("insert dft module.\n");
    syscall_table = (unsigned long *)kallsyms_lookup_name("sys_call_table");
    orig_syscall[SYS_DFT_alloc] = (unsigned long)syscall_table[SYS_DFT_alloc];
    orig_syscall[SYS_DFT_new_activation] = (unsigned long)syscall_table[SYS_DFT_new_activation];
    orig_syscall[SYS_DFT_new_data] = (unsigned long)syscall_table[SYS_DFT_new_data];
    clear_and_save_cr0();
    syscall_table[SYS_DFT_alloc] = (unsigned long)&DFT_alloc;
    setback_cr0();
    init_table();
    return 0;
}

void __exit exit_dft() {
    clear_and_save_cr0();
    syscall_table[SYS_DFT_alloc] = (unsigned long)syscall_table[SYS_DFT_alloc];
    syscall_table[SYS_DFT_new_activation] = (unsigned long)syscall_table[SYS_DFT_new_activation];
    syscall_table[SYS_DFT_new_data] = (unsigned long)syscall_table[SYS_DFT_new_data];
    setback_cr0();
    printk("remove dft module.\n");
}

module_init(init_dft);
module_exit(exit_dft);
MODULE_LICENSE("GPL");
