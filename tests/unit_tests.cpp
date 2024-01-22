#include <sstream>

#include <gtest/gtest.h>
#include "test_functions.hpp" // include your library here
#include "lib/mylib/MyClass.hpp"

TEST(MyLibUnitTestSuite, BasicTest1) {
  std::ostringstream out;
  MyClass printer(out);
  printer.Print("Hello, World!");
  std::vector<std::string> out_by_words = SplitString(out.str());
  ASSERT_EQ(out_by_words.size(), 2);
  ASSERT_EQ(out_by_words[0], "Hello,");
  ASSERT_EQ(out_by_words[1], "World!");
}