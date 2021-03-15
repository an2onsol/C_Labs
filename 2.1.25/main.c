#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"

void input(int* ch, int* zn) {
	int flag = 0;
	printf("Enter the numerator: ");
	while(flag != 1){
		flag = scanf("%d", ch);
		if(flag != 1){
			while(getchar() != '\n');
			system("cls");
			printf("Enter the numerator: ");
		}	
	}

	flag = 0;

	printf("Enter the denominator: ");
	while(flag != 1){
		flag = scanf("%d", zn);
		if(flag != 1){
			while(getchar() != '\n');
			system("cls");
			printf("Enter the denominator: ");
		}	
	}

	if (*zn == 0){
		system("cls");
		printf("Denominator can't be zero.\n");
		input(ch, zn);
	}
	system("cls");	
}

void output(int* ch, int* zn) {
	float c = *ch / (float)*zn;
	printf("%d/%d  %f  %E\n", *ch, *zn, c, c);
}

void outputR(int* ch, int* zn) {
	if(*ch == 0){
		printf("Can't do Reverse(numenator = 0)\n");
	}
	else{
	float cR = *zn / (float)*ch;
	printf("%d/%d  %f  %E\n", *zn, *ch, cR, cR);
	}
}
structure reduction(int ch, int zn) {
	float i = 2;
	while (ch / i >= 1 || zn / i >= 1){
		if (ch % (int)i == 0 && zn % (int)i == 0){
			ch /= i;
			zn /= i;
		}
		else{
			i++;
		}
	}
	structure out;
	out.ch = ch;
	out.zn = zn;
	return out;
}
void info() {
	printf("Version: v1.0\nAuthor: student of group 053501 Anton Solianik\n");
}

int main() {
	int zn, ch, status, flag1 = 0;
	while (1) {
		int flag;
		printf("1.Input\n2.Output\n3.Reverse\n4.Reduction\n5.Info\n6.Exit\n");
		flag = scanf("%d", &status);
		if(flag != 1){
			while(getchar() != '\n');
			system("cls");
			printf("Incorrect \n");
		}
		if (status == 1) {
			system("cls");
			input(&ch, &zn);
			flag1 = 1;
		}
		else if (status == 2) {
			system("cls");
			if (flag1) {
				output(&ch, &zn);
			}
			else {
				printf("Enter the numerator/denominator before Output\n");
			}
		}
		else if (status == 3) {
			system("cls");
			if (flag1) {
				outputR(&ch, &zn);
			}
			else {
				printf("Enter the numerator/denominator before Reverse\n");
			}
		}
		else if (status == 5) {
			system("cls");
			info();
		}
		else if (status == 4){
			system("cls");
			if (flag1) {
				structure x = reduction(ch, zn);
				printf("%d/%d\n", x.ch, x.zn);
			}
			else {
				printf("Enter the numerator/denominator before Reduction\n");
			}
		}
		else if (status == 6) {
			system("cls");
			break;
		}
		else {
			system("cls");
		}
	}
	return 0;
}
