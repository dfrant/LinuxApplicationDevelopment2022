CFLAGS+= -O0 -g
GENERATES = range *.log *.txt

compile: range

test: compile
	gdb -x test1.gdb --args ./range 1 12 | grep @@@ > test1.log
	diff test1.log test1.ref
	
	gdb -x test2.gdb --args ./range -100 100 3 | grep @@@ > test2.log
	diff test2.log test2.ref
clean:
	rm -rf $(GENERATES)
