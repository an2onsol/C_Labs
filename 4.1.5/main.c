#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"


char* func(const char* str){
	int size, max_size = 0, flag, first, i = 0;
	
	while(str[i] != '\0'){
		size = 0;
		flag = 1;
		int table[127] = {0};
		while(str[i] != ' '){
			if(str[i] == '\0'){
				break;
			}
			if(table[(int)str[i]] == 0){
				table[(int)str[i]] = 1;
			}
			else{
				flag = 0;
			}
			size++;
			i++;
		}
		if(max_size <= size && flag == 1){
			
			max_size = size;
			first = i - size;
		}
		i++;
		
	}
	char* result = (char*)malloc(max_size * sizeof(char));
	if (result == NULL){
		exit(2);
	}
	for(i = 0; i < max_size; i++){
		result[i] = str[first + i];
	}
	return result;
}
int main() {
	char* x = func("zxcv asdfgh qqqqqqqqq jjjdjjdjj\0");
	free(x);
	printf("%s", x);
	return 0;
}
