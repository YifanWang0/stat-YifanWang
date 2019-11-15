all: stat_main.o
	gcc -o program stat_main.o

stat_main.o: stat_main.c
	gcc -c stat_main.c

run:
	./program

clean:
	rm *.o
	rm *~

memcheck:
	valgrind --leak-check:yes ./test_stat
