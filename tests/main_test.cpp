#include <sstream>

#include <gtest/gtest.h>
#include "ProjectIntegrationTestSuite.hpp"
#include "test_functions.hpp"
#include "lib/ui/ui_functions.hpp" // include your library here

TEST_F(ProjectIntegrationTestSuite, InitTest) {
  ASSERT_TRUE(std::filesystem::is_directory(kTemporaryDirectoryName));
}

TEST_F(ProjectIntegrationTestSuite, PositiveTest1) {
  std::ostringstream out;
  ASSERT_EQ(StartConsoleUI(SplitString("test World"), out), 0);
}

TEST_F(ProjectIntegrationTestSuite, PositiveOutputTest1) {
  std::ostringstream out;
  StartConsoleUI(SplitString("test World"), out);
  ASSERT_EQ(out.str(), "Hello, World!\n");
}

TEST_F(ProjectIntegrationTestSuite, NegativeTest1) {
  std::ostringstream out;
  ASSERT_EQ(StartConsoleUI(SplitString("test"), out), 1);
}

TEST_F(ProjectIntegrationTestSuite, NegitiveOutputTest1) {
  std::ostringstream out;
  StartConsoleUI(SplitString("test"), out);
  ASSERT_EQ(out.str(), "Insufficient arguments\n");
}
