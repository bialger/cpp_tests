#include <iostream>

#include "lib/mylib/MyClass.h"

int main() {
  MyClass printer(std::cout);
  printer.Print("Hello, World!\n");
  return 0;
}
