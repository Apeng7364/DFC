CFLAGS = -D_REENTRANT -Wall -pedantic -Isources -std=c99 -O3

ifdef DEBUG
CFLAGS += -g
LDFLAGS += -g
endif

TARGETS = libc_printf.a

all: $(TARGETS)

sources/c_printf.o: sources/c_printf.c

libc_printf.a: sources/c_printf.o
	ar rcs $@ $^

clean:
	rm -f $(TARGETS) *~ */*~ */*.o

install:
	install -m644 sources/c_printf.h ~/include/c_printf.h
	install -m644 libc_printf.a ~/lib/libc_printf.a

uninstall:
	rm -f ~/include/c_printf.h
	rm -f ~/lib/libc_printf.a