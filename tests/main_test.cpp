#include <sstream>

#include <gtest/gtest.h> // include your library here

std::vector<std::string> SplitString(const std::string& str) {
  std::istringstream iss(str);

  return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

TEST(BasicTestSuite, BasicTest1) {
  std::ostringstream out;
  out << "Hello, World!";
  ASSERT_EQ(out.str(), "Hello, World!");
}
