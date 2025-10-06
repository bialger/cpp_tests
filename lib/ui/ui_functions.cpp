#include "lib/mylib/MyClass.hpp"
#include "ui_functions.hpp"

int32_t StartConsoleUI(const std::vector<std::string>& args, std::ostream& out) {
  if (args.size() < 2) {
    out << "Insufficient arguments\n";
    return 1;
  }

  MyClass printer(out);
  printer.Print("Hello, " + args[1] + "!\n");
  return 0;
}
