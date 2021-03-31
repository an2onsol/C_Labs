#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"
void input(int* x, int* y){
	int flag = 0;
	while(flag != 2 || *x < 0 || *x > 8 || *y < 0 || *y > 8){
		flag = scanf("%d %d", x, y);
		if(flag != 2 || *x < 0 || *x > 8 || *y < 0 || *y > 8){
			while(getchar() != '\n');
			printf("Incorrect \n");
		}
		
	}
}
int kingUnderAttack(int **board, int kx, int ky){
	int i, j;
	for (i = 0; i < 8; i++){
		if(board[i][ky] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, ky);
			return 1;
		}
	}
	for (i = 0; i < 8; i++){
		if(board[kx][i] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, kx);
			return 1;
		}
	}
	i = kx;
	j = ky;
	while(j >= 0 && i >= 0 && j <= 7 && i <= 7){
		if(board[i][j] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, j);
			return 1;
		}
		i++;
		j++;
	}
	i = kx;
	j = ky;
	while(j >= 0 && i >= 0 && j <= 7 && i <= 7){
		if(board[i][j] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, j);
			return 1;
		}
		i--;
		j--;
	}
	i = kx;
	j = ky;
	while(j >= 0 && i >= 0 && j <= 7 && i <= 7){
		if(board[i][j] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, j);
			return 1;
		}
		i--;
		j++;
	}
	i = kx;
	j = ky;
	while(j >= 0 && i >= 0 && j <= 7 && i <= 7){
		if(board[i][j] == 2){
			printf("King is under attack by queen on (%d;%d)\n", i, j);
			return 1;
		}
		i++;
		j--;
	}
	printf("King isnt under attack by queen\n");
	return 0;
}

int main() {
	char ch;
	int x, y, i, j, result, kx, ky;
	int** board = (int**)malloc(sizeof(int*) * 8);
	if(board == NULL){
		exit(2);
	}
	for (i = 0; i < 8; i++){
		board[i] = (int*)malloc(sizeof(int*) * 8);
		for(j = 0; j < 8; j++){
			if(board[i] == NULL){
		    	exit(2);
	    	}
			board[i][j] = 0;
		}
	}
	printf("Enter king position\n");
	input(&x, &y);
	kx = x;
	ky = y;
	board[x][y] = 1;
	while(1){
		printf("Would you like to enter queen position\ny/n\n");
		while(getchar() != '\n');
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y'){
			printf("Enter position\n");
			input(&x, &y);
			if(board[x][y] != 0){
				printf("Position has already used\n");
			}
			else{
				board[x][y] = 2;
			}
			
		}
		else if(ch == 'n' || ch == 'N'){
			break;
		}
		
	}
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	
	result = kingUnderAttack(board, kx, ky);
	printf("%d\n", result);
	for(i = 0; i < 8; i++){
        free(board[i]);
    }
    free(board);
	return 0;
}
