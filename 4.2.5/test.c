#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test() {
    char str1[7];
    const char* str2 = "ghijkl";
    strcp(str1, str2);
    for(int i = 0; i < 7; i++){
        assert(str1[i] == str2[i]);
    }
    
    assert(strcm("abcd", "abcd") == 1);
    assert(strcm("abcd", "dbca") == 0);
}

#undef main

int main() {
    test();
    return 0;
}
