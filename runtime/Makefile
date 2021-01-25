all:
	cd c_printf && make && cd ..
	cd threadpool && make && cd ..
	cd dfc && make && cd ..

# test/And_dfc.o: test/And_dfc.c
# 	$(CC) -c -fPIC ${CFLAGS} -o $@ $<
	
# test/And_dfc: test/And_dfc.o
# 	$(CC) -o $@ $< $(LDFLAGS) 

# test: test/And_dfc
# 	LD_PRELOAD=dfc/libdfc.so test/And_dfc

clean:
	cd c_printf && make clean && cd ..
	cd threadpool && make clean && cd ..
	cd dfc && make clean && cd ..

install:
	cd c_printf && make install && cd ..
	cd threadpool && make install && cd ..
	cd dfc && make install && cd ..

uninstall:
	cd c_printf && make uninstall && cd ..
	cd threadpool && make uninstall && cd ..
	cd dfc && make uninstall && cd ..