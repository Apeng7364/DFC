CFLAGS = -D_REENTRANT -Wall -pedantic -I/home/apeng/include -Isrc -I../c_printf/sources -I../threadpool/src -std=c99 -O3
LDLIBS = 

ifdef DEBUG
CFLAGS += -g
LDFLAGS += -g
endif

TARGETS = libdfc.a

all: $(TARGETS)

src/dfc.o: src/dfc.c

libdfc.a: src/dfc.o ../c_printf/sources/c_printf.o ../threadpool/src/threadpool.o
	ar rcs $@ $^

clean:
	rm -f $(TARGETS) *~ */*~ */*.o

install:
	install -m644 src/dfc.h ~/include/dfc.h
	install -m644 libdfc.a ~/lib/libdfc.a

uninstall:
	rm -f ~/lib/libdfc.a
	rm -f ~/include/dfc.h