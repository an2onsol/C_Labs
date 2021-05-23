#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test() {
    int maxSum = 100;
    Service* serv = (Service*)malloc(sizeof(Service));
    if(serv == NULL){
		exit(2);
	}
    serv->serviceTime = rand() % 100;
    serv->next = NULL;
    serv->prev = NULL;
    serv->number = 0;
    Service* first = serv;

    Service* q = (Service*)malloc(sizeof(Service));
    if(q == NULL){
		exit(2);
	}
    q->serviceTime = 10;
    q->prev = serv;
    q->next = NULL;
    q->number = 1;
    serv->next = q;
    serv = serv->next;

    Service* w = (Service*)malloc(sizeof(Service));
    if(w == NULL){
		exit(2);
	}
    w->serviceTime = 30;
    w->prev = serv;
    w->next = NULL;
    w->number = 2;
    serv->next = w;
    serv = serv->next;

    Service* e = (Service*)malloc(sizeof(Service));
    if(e == NULL){
		exit(2);
	}
    e->serviceTime = 20;
    e->prev = serv;
    e->next = NULL;
    e->number = 3;
    serv->next = e;
    serv = serv->next;

    Service* r = (Service*)malloc(sizeof(Service));
    if(r == NULL){
		exit(2);
	}
    r->serviceTime = 100;
    r->prev = serv;
    r->next = NULL;
    r->number = 4;
    serv->next = r;
    serv = serv->next;
    serv = first;
    

    BSrt(serv);
    serv = first;
    assert(Result(serv, maxSum) == 231);
    free(q);
    free(w);
    free(e);
    free(r);
    free(serv);

} 

#undef main

int main() {
    test();
    return 0;
}
