#include "main.h"
#include <assert.h>
#include <stdlib.h>

void test() {
    int i, j, kx, ky;
    int** board = (int**)malloc(sizeof(int*) * 8);
    if(board == NULL){
		exit(2);
	}
	for (i = 0; i < 8; i++){
		board[i] = (int*)malloc(sizeof(int*) * 8);
        if(board[i] == NULL){
		    exit(2);
	    }
		for(j = 0; j < 8; j++){
			board[i][j] = 0;
		}
	}

    kx = 2;
    ky = 2;
    board[kx][ky] = 1;
    board[2][4] = 2;
    assert(kingUnderAttack(board, kx, ky) == 1);
    board[kx][ky] = 0;
    board[2][4] = 0;

    kx = 7;
    ky = 7;
    board[kx][ky] = 1;
    board[1][1] = 2;
    assert(kingUnderAttack(board, kx, ky) == 1);
    board[kx][ky] = 0;
    board[1][1] = 0;

    kx = 2;
    ky = 4;
    board[kx][ky] = 1;
    board[7][7] = 2;
    assert(kingUnderAttack(board, kx, ky) == 0);

    for(i = 0; i < 8; i++){
        free(board[i]);
    }
    free(board);
} 

#undef main

int main() {
    test();
    return 0;
}
