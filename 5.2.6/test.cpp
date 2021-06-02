#include <cassert>
#include <iostream>
#include "Tree.h"

void test() {
  Tree tree;
  std::string str = "hello";
  for (auto i : str) {
    tree.insert(i);
  }
  assert(tree.count('h') == 3);
  assert(tree.count('e') == 0);
}

#undef main
int main() {
  test();
  return 0;
}