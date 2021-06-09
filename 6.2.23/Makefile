all: build mtest

build: main.c Manager.c
	gcc main.c Manager.c -o main -lm 
run:
	./main
mtest:
	gcc -ftest-coverage -fprofile-arcs -O0 -o test test.c Manager.c
	./test
	gcov -abcfu Dormitory.cpp
valgrind:
	valgrind --leak-check=full ./main
linter:
	cppcheck -q --enable=all --inconclusive main.c
	
	
