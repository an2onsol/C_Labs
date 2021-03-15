all: build mtest

build: main.c
	gcc main.c -o main -lm -std=c89
run:
	./main
mtest:
	gcc -o test -Dmain=_main main.c test.c
	./test
valgrind:
	valgrind --leak-check=full ./main
linter:
	cppcheck -q --enable=all --inconclusive main.c
	
	
