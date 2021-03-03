#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void palindrome(int x) {
	int i = 0, dec = x, flag = 1;
	int* bin = (int*) malloc(((int)(log(x) / log(2)) + 1) * sizeof(int));
	if(bin == NULL){
		exit(2);
	}
	while (x >= 1) {
		bin[i] = x % 2;
		x /= 2;
		i++;
	}
	int j;
	for (j = 0; j <= i / 2; j++) {
		if (bin[j] != bin[i - 1 - j]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		for (j = 0; j < i; j++) {
			printf("%d", bin[j]);
		}
		printf("--%d \n", dec);
	}
	free(bin);
}

int main() {
	int m = 0, i, flag = 0;
	while(flag != 1 || m < 1){
		flag = scanf("%d", &m);
		if(flag != 1 || m < 1){
			while(getchar() != '\n');
			printf("Incorrect \n");
		}
		
	}
	printf("1--1 \n");
	for (i = 3; i <= m; i += 2) {
		palindrome(i);
	}
	return 0;
}
