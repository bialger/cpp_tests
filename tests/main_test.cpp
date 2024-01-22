#include <sstream>

#include <gtest/gtest.h>
#include "ProjectIntegrationTestSuite.hpp"
#include "test_functions.hpp" // include your library here
#include "lib/mylib/MyClass.h"

TEST_F(ProjectIntegrationTestSuite, InitTest) {
  ASSERT_TRUE(std::filesystem::is_directory(kTemporaryDirectoryName));
}
