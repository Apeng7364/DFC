obj-m += mod_dfc.o
mod_dfc-objs := dft_init.o dft.o 
PWD:= $(shell pwd)
KERNELDIR:= /lib/modules/$(shell uname -r)/build
EXTRA_CFLAGS= -O0
all:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
install:
	cp dft.h ~/include/
uninstall:
	rm ~/include/dft.h