CFLAGS = -D_REENTRANT -Wall -pedantic -Isrc -std=c99 -O3

ifdef DEBUG
CFLAGS += -g
LDFLAGS += -g
endif

TARGETS = libc_printf.a libc_printf.so

all: $(TARGETS)

src/c_printf.o: src/c_printf.c

libc_printf.a: src/c_printf.o
	ar rcs $@ $^

libc_printf.so: src/c_printf.c
	$(CC) -shared -fPIC ${CFLAGS} -o $@ $< 

clean:
	rm -f $(TARGETS) *~ */*~ */*.o

install:
	install -m644 src/c_printf.h ~/include/c_printf.h
	install -m644 libc_printf.a ~/lib/libc_printf.a
	install -m755 libc_printf.so ~/lib/libc_printf.so

uninstall:
	rm -f ~/include/c_printf.h
	rm -f ~/lib/libc_printf.a
	rm -f ~/lib/libc_printf.so
