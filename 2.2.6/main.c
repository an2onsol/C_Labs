#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"

int factorial(int n){
    int f = 1;
	int i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}


int sum(float x, float e){
	int n = 0;
	float sum = 0;
	while(fabs(sin(x) - sum) >= e){
		n++;
		sum += pow(-1, n - 1)*pow(x, 2 * n - 1) / factorial(2 * n - 1);
	}
	return n;
}

int main() {
	short flag = 0;
	float x = 5, e;
	printf("Enter x [-pi/2 ; pi/2]:\n");
	while (flag != 1 || x > acos(-1) / 2 || x < -acos(-1) / 2) {
		flag = scanf("%f", &x);
		if (flag != 1 || x > acos(-1) / 2 || x < -acos(-1) / 2) {
			while (getchar() != '\n');
			system("cls");
			printf("Enter x [-pi/2 ; pi/2]:\n");
		}
	}
	flag = 0;
	printf("Enter epsilon:\n");
	while (flag != 1) {
		flag = scanf("%f", &e);
		if (flag != 1) {
			while (getchar() != '\n');
			system("cls");
			printf("Enter epsilon: ");
		}
	}
	printf("sin = %f, e = %f, n = %d",sin(x), e, sum(x, e));
	return 0;
}
