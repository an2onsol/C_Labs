#include "main.h"
#include <assert.h>
int test() {
    assert(sum(1, 0.001) == 3);
    assert(sum(0.5, 0.01) == 2);
} 

#undef main

int main() {
    test();
}
