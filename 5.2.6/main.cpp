#include <iostream>
#include "Tree.h"

int main() {
  Tree tree;
  std::string str;
  std::cout << "Enter string\n";
  std::cin >> str;
  for (auto i : str) {
    tree.insert(i);
  }
  std::cout << "Enter char\n";
  char ch;
  std::cin >> ch;
  std::cout << "There are " <<tree.count(ch) << " under this node";
  return 0;
}
