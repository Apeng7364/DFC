CFLAGS = -D_REENTRANT -Wall -pedantic -Isrc -std=c99 -O3
LDLIBS = -lpthread

ifdef DEBUG
CFLAGS += -g
LDFLAGS += -g
endif

TARGETS = tests/thrdtest tests/heavy tests/shutdown \
	libthreadpool.a

all: $(TARGETS)

tests/shutdown: tests/shutdown.o src/threadpool.o
tests/thrdtest: tests/thrdtest.o src/threadpool.o
tests/heavy: tests/heavy.o src/threadpool.o
src/threadpool.o: src/threadpool.c src/threadpool.h
tests/thrdtest.o: tests/thrdtest.c src/threadpool.h
tests/heavy.o: tests/heavy.c src/threadpool.h

# Short-hand aliases
shared: libthreadpool.so
static: libthreadpool.a

# libthreadpool.so: src/threadpool.c src/threadpool.h
# 	$(CC) -shared -fPIC ${CFLAGS} -o $@ $< ${LDLIBS}

# src/libthreadpool.o: src/threadpool.c src/threadpool.h
# 	$(CC) -c -fPIC ${CFLAGS} -o $@ $<

libthreadpool.a: src/threadpool.o
	ar rcs $@ $^

clean:
	rm -f $(TARGETS) *~ */*~ */*.o

test:
	./tests/shutdown
	./tests/thrdtest
	./tests/heavy

install:
	install -m644 src/threadpool.h ~/include/
	install -m644 libthreadpool.a ~/lib/

uninstall:
	rm -f ~/include/threadpool.h
	rm -f ~/lib/libthreadpool.a
