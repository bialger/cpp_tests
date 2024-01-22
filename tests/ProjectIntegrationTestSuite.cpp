#include "ProjectIntegrationTestSuite.hpp"

void ProjectIntegrationTestSuite::SetUp() {
  std::filesystem::create_directories(dirname);
}

void ProjectIntegrationTestSuite::TearDown() {
  std::filesystem::remove_all(dirname);
}
