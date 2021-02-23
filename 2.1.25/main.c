#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

void input(int* ch, float* zn) {
	printf("Введите числитель: ");
	scanf("%d", ch);
	printf("Введите знаменатель: ");
	scanf("%f", zn);
	if (*zn == 0){
		system("cls");
		printf("Введите знаменатель не равный нулю.\n");
		input(ch, zn);
	}
	system("cls");	
}

void output(int* ch, float* zn) {
	float c = *ch / *zn;
	printf("%d/%1.0f  %f  %E\n", *ch, *zn, c, c);
}

void outputR(int* ch, float* zn) {
	float cR = *zn / *ch;
	printf("%1.0f/%d  %f  %E\n", *zn, *ch, cR, cR);
}

void info() {
	printf("Версия программы: v1.0\nАвтор: студент группы 053501 Соляник Антон\n");
}

int main() {
	int ch, status, flag1 = 0;
	float zn;
	setlocale(LC_ALL, "Rus");
	while (1) {
		printf("1.Ввод\n2.Вывод\n3.Обратное\n4.Информация\n5.Выход\n");
		scanf("%d", &status);
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
				printf("Вы не ввели значения числителя и знаменателя\n");
			}
		}
		else if (status == 3) {
			system("cls");
			if (flag1) {
				outputR(&ch, &zn);
			}
			else {
				printf("Вы не ввели значения числителя и знаменателя\n");
			}
		}
		else if (status == 4) {
			system("cls");
			info();
			
		}
		else if (status == 5) {
			system("cls");
			break;
		}
		else {
			system("cls");
		}
	}
	return 0;
}
