all: build run test

build: main.c
	gcc main.c -o main -lm -std=c89

run:
	./main

test: 
	./main < Tests/inputTest1.txt > Tests/outputTest1.txt
	./main < Tests/inputTest2.txt > Tests/outputTest2.txt
	./main < Tests/inputTest3.txt > Tests/outputTest3.txt
	diff Tests/correct1.txt Tests/outputTest1.txt
	diff Tests/correct2.txt Tests/outputTest2.txt
	diff Tests/correct3.txt Tests/outputTest3.txt
