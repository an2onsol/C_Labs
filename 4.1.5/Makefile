all: build mtest valgrind 

build: main.c
	gcc main.c -o main -lm 
run:
	./main
mtest:
	gcc -o test -Dmain=_main main.c test.c -lm
	./test
valgrind:
	valgrind ./main
linter:
	cpplint *.c
	
	
