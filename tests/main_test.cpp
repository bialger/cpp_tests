#include <sstream>
#include <filesystem>

#include <gtest/gtest.h> // include your library here
#include "lib/mylib/MyClass.h"

struct TemporaryDirectoryTestSuite : public testing::Test { // special test structure
  const std::string dirname = "./gtest_tmp";

  void SetUp() override { // method that is called at the beginning of every test
    std::filesystem::create_directories(dirname);
  }

  void TearDown() override { // method that is called at the end of every test
    std::filesystem::remove_all(dirname);
  }
};

std::vector<std::string> SplitString(const std::string& str) {
  std::istringstream iss(str);

  return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

TEST_F(TemporaryDirectoryTestSuite, InitTest) {
  ASSERT_TRUE(std::filesystem::is_directory(dirname));
}

TEST(MyLibUnitTestSuite, BasicTest1) {
  std::ostringstream out;
  MyClass printer(out);
  printer.Print("Hello, World!");
  ASSERT_EQ(out.str(), "Hello, World!");
}
