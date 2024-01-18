#include <iostream>

#include "lib/mylib/MyClass.h"

int main() {
  MyClass printer(std::cout);
  printer.Print("Hello, World!");
  return 0;
}
