#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

typedef struct {
	char* language;
	char* subjects;
	char* code;
	char* article;
	char* comment;
	int  dateAdded;
} Manager;

typedef struct {
	Manager* manager;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct {
	Node* head;
	Node* tail;
	int count;
} List;

List* catalog;

void create(List* list);
void push(Manager* temp);
char* read(FILE* file);
Manager* managerRead(FILE* file);
void showList(int choice);
void addComment(Manager* temp, char* string);
Manager* Search(Node* head, char* search);
void Catalog(Node* head);
void del(Node* head);
void Menu();