all: build mtest

build: main.c
	g++ main.cpp -o main -lm 
run:
	./main
mtest:
	g++ -o test -Dmain=_main main.cpp test.cpp -lm
	./test
valgrind:
	valgrind -s --track-origins=yes ./main
linter:
	cppcheck -q --enable=all --inconclusive main.cpp
	
	
