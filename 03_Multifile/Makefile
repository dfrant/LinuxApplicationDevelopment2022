GENERATES = prog prog-* *.a *.so README
TRASH = *.o *~ o.* *.log
CFLAGS = -fPIC

all: README prog prog-a prog-so 

prog: const.o fun.o prog.o

lib.a:
	ar -rcs liboutput_static.a const.o fun.o

lib.so:
	cc -shared fun.o const.o -o libout.so

prog-a: lib.a
	cc -L. prog.o -loutput_static -o prog-a	

prog-so: lib.so
	cc -L. prog.o -lout -o prog-so

README: prog
	./$< 2> $@

fun.o: outlib.h

test:
	./prog > prog_test1.log 2>> prog_test1.log
	./prog-a > prog-a_test1.log 2>> prog-a_test1.log
	LD_LIBRARY_PATH=`pwd` ./prog-so > prog-so_test1.log 2>> prog-so_test1.log
	
	./prog arg1 > prog_test2.log 2>> prog_test2.log
	./prog-a arg1 > prog-a_test2.log 2>> prog-a_test2.log
	LD_LIBRARY_PATH=`pwd` ./prog-so arg1 > prog-so_test2.log 2>> prog-so_test2.log
	
	./prog arg1 arg2 arg3 > prog_test3.log 2>> prog_test3.log
	./prog-a arg1 arg2 arg3 > prog-a_test3.log 2>> prog-a_test3.log
	LD_LIBRARY_PATH=`pwd` ./prog-so arg1 arg2 arg3 > prog-so_test3.log 2>> prog-so_test3.log
	
	diff3 *test1.log
	diff3 *test2.log
	diff3 *test3.log

clean:
	rm -f $(TRASH) $(GENERATES)
