#include <filesystem>

#include "ProjectIntegrationTestSuite.hpp"

void ProjectIntegrationTestSuite::SetUp() {
  std::filesystem::create_directories(kTemporaryDirectoryName);
}

void ProjectIntegrationTestSuite::TearDown() {
  std::filesystem::remove_all(kTemporaryDirectoryName);
}
