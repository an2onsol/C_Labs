#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main.h"



void strcp(char *dst, const char *src){
    while(*dst++ = *src++);
}

int strcm(const char *str1, const char *str2){
    while(*str1 && *str2){
        if (*str1 != *str2){
            return 0;
        }
        *str1++;
        *str2++;
    }
    return 1;
}

int main() {
	int i = 0, j, flag, n;
	char temp[128];
	word* db =(word*)malloc(100 * sizeof(word));
	FILE *fin = fopen("input.txt", "r");
	while(fscanf(fin, "%128s", temp) == 1){
		flag = 1;
		for(j = 0; j < i; j++){
			if (strcm(db[j].text, temp)){
				db[j].count++;
				flag = 0;
				break;		
			}
		}
		if(flag == 1){
			db[i].text = (char*)malloc(sizeof(char)*128);
			strcp(db[i].text, temp);
			db[i].count = 1;
			i++;
		}
	}
	n = i;
	for (i = n - 1; i >= 0; i--){
    	for (int j = 0; j < i; j++){
        	if (db[j].count < db[j + 1].count){
          		word tmp = db[j];
          		db[j] = db[j + 1];
          		db[j + 1] = tmp;
      		}
    	}
  	}
	int n1 = n;
	if (n > 20){
		n = 20;
	}
	for(j = 0; j < n; j++){
		printf("%s %d\n", db[j].text, db[j].count);
	}
	for(i = 0; i < n1; i++){
		free(db[i].text);
	}
	fclose(fin);
	free(db);
	return 0;
}
