#include "main.h"
#include <assert.h>
#include <stdlib.h>

void test() {
    catalog = (List*)malloc(sizeof(List));
    FILE* file;
    errno_t err = fopen_s(&file, "catalogS.txt", "r+");
	if (err != 0) {
		printf("File error");
		exit(-1);
	}
    create(catalog);
    assert(catalog->count == 0);

    while (!feof(file))
		push(managerRead(file));
    assert(catalog->head->manager->language == "C++");
    
    Manager* search = Search(catalog->head, "TestCode.txt");
    Manager* searchError = Search(catalog->count, "RandomCode");
    assert(searchError == NULL);

    char string[256] = "testComment";
    addComment(search, string);
    assert(search->comment == "comment1 testComment");

    showList(1);
    showList(2);
    showList(3);
    
    Catalog(catalog->head);
    del(catalog->head);
} 

#undef main

int main() {
    test();
    return 0;
}