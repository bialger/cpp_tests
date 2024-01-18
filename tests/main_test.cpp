#include <sstream>

#include <gtest/gtest.h> // include your library here
#include "lib/mylib/MyClass.h"

std::vector<std::string> SplitString(const std::string& str) {
  std::istringstream iss(str);

  return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

TEST(MyLibUnitTestSuite, BasicTest1) {
  std::ostringstream out;
  MyClass printer(out);
  printer.Print("Hello, World!");
  ASSERT_EQ(out.str(), "Hello, World!");
}
