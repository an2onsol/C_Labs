#include "main.h"
#include <assert.h>

int test() {
    structure x = reduction(130, 260);
    assert(x.ch == 1 && x.zn == 2);
    x = reduction(24, 26);
    assert(x.ch == 12 && x.zn == 13);
    x = reduction(20, 200);
    assert(x.ch == 1 && x.zn == 10);
} 

#undef main

int main() {
    test();
}