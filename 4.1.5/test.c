#include "main.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test() {
    int i;
    char* x = func("zxcv asdfgh qqqqqqqqq jjjdjjdjj");
    char* y = "asdfgh";
    for(i = 0; i < 6; i++){
        assert(x[i] == y[i]);
    }
    x = func("asdasd vbnmasdfg qwerty ghjghjghjghj");
    y = "vbnmasdfg";
    for(i = 0; i < 9; i++){
        assert(x[i] == y[i]);
    }
    x = func("qwerty asdfghj zxczxzxczxczxc");
    y = "asdfghj";
    for(i = 0; i < 7; i++){
        assert(x[i] == y[i]);
    }
    free(x);
}

#undef main

int main() {
    test();
    return 0;
}
