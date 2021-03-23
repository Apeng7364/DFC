CFLAGS = -D_REENTRANT -Wall -pedantic -fPIC -I/home/apeng/include -Isrc -I../c_printf/src -I../threadpool/src -L../threadpool/ -L../c_printf -std=c99 -O3
LDLIBS = -lc_printf -lthreadpool

ifdef DEBUG
CFLAGS += -g
LDFLAGS += -g
endif

TARGETS = libdfc.a libdfc.so

all: $(TARGETS)

src/dfc.o: src/dfc.c

libdfc.a: src/dfc.o ../c_printf/src/c_printf.o ../threadpool/src/threadpool.o
	ar rcs $@ $^

libdfc.so: src/dfc.c
	$(CC) -shared -fPIC ${CFLAGS} -o $@ $< ${LDLIBS}

clean:
	rm -f $(TARGETS) *~ */*~ */*.o

install:
	install -m644 src/dfc.h ~/include/dfc.h
	install -m644 libdfc.a ~/lib/libdfc.a
	install -m755 libdfc.so ~/lib/libdfc.so

uninstall:
	rm -f ~/include/dfc.h
	rm -f ~/lib/libdfc.a
	rm -f ~/lib/libdfc.so