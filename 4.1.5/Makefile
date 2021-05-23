all: build mtest valgrind linter

build: main.c
	gcc main.c -o main -lm -std=c89
run:
	./main
mtest:
	gcc -o test -Dmain=_main main.c test.c -lm
	./test
valgrind:
	valgrind --leak-check=full ./main
linter:
	cpplint *.c
	
	
