#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "main.h"

void create(List* list) {
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
}

void push(Manager* temp) {
	Node* newNode = (Node*)malloc(sizeof(Manager));
	newNode->next = NULL;
	newNode->manager = temp;

	if (catalog->head == NULL)
	{
		catalog->head = newNode;
		catalog->tail = newNode;
	}
	else
	{
		catalog->tail->next = newNode;
		newNode->prev = catalog->tail;
		catalog->tail = newNode;
	}

	catalog->count++;
}

char* read(FILE* file) {
	char buffer[256];
	fgets(buffer, 256, file);
	int lenght = strlen(buffer);
	buffer[lenght - 1] = '\0';
	char* string = (char*)calloc(++lenght, sizeof(char));
	if (string == NULL)
	{
		exit(-1);
	}
	strcpy_s(string, lenght, buffer);
	return string;
}

Manager* managerRead(FILE* file) {
	char buffer[256];
	Manager* temp = (Manager*)malloc(sizeof(Manager));
	temp->language = read(file);
	temp->subjects = read(file);
	temp->code = read(file);
	temp->article = read(file);
	temp->comment = read(file);
	fgets(buffer, 256, file);;
	temp->dateAdded = atoi(buffer);
	return temp;
}

void showList(int choice) {
	Node* temp = catalog->head;	
	int count = 0;
	system("cls");
	while (temp) {
		printf("%d.", ++count);
		if (choice == 1)
			printf("%s\n", temp->manager->language);
		else if (choice == 2)
			printf("%s\n", temp->manager->article);
		else if (choice == 3)
			printf("%s\n", temp->manager->subjects);
		temp = temp->next;
	}
}

void addComment(Manager* temp, char* string) {
	char result[256];
	sprintf(result, "%s %s", temp->comment, string);
	free(temp->comment);
	temp->comment = (char*)calloc(strlen(result), sizeof(char));
	if (temp->comment == NULL)
		printf("Error");
	for (int i = 0; i < strlen(result); i++)
		temp->comment[i] = result[i];
}

Manager* Search(Node* head, char* search) {
	Node* temp = head;
	while (temp) {
		int k = strlen(search);
		for (int i = 0; i < strlen(search); i++) {
			if (search[i] == temp->manager->code[i])
				k--;
		}
		if (k == 0) return temp->manager;
		temp = temp->next;
	}
	return NULL;
}

void Catalog(Node* head) {
	Node* temp = head;
	while (temp) {
		printf("%s\n", temp->manager->language);
		printf("%s\n", temp->manager->subjects);
		printf("%s\n", temp->manager->code);
		printf("%s\n", temp->manager->article);
		printf("%s\n", temp->manager->comment);
		printf("%d\n\n", temp->manager->dateAdded);
		temp = temp->next;
	}
}

void del(Node* head) {
	Node* temp;
	while (head) {
		temp = head;
		free(head->manager->article);
		free(head->manager->code);
		free(head->manager->comment);
		free(head->manager->language);
		free(head->manager->subjects);
		free(head->manager);
		head = head->next;
		free(temp);

	}
}
