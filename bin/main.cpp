#include <iostream>

#include "ui/ui_functions.hpp"
#include "mylib/MyClass.hpp"

int main(int32_t argc, char** argv) {
  std::vector<std::string> args = std::vector<std::string>(argv, argv + argc);
  return StartConsoleUI(args, std::cout);
}
