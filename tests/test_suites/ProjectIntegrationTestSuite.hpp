#ifndef TEMPORARYDIRECTORYTESTSUITE_HPP_
#define TEMPORARYDIRECTORYTESTSUITE_HPP_

#include <string>

#include <gtest/gtest.h>

struct ProjectIntegrationTestSuite : public testing::Test { // special test structure
  const std::string kTemporaryDirectoryName = "./gtest_tmp";

  void SetUp() override; // method that is called at the beginning of every test

  void TearDown() override; // method that is called at the end of every test
};

#endif // TEMPORARYDIRECTORYTESTSUITE_HPP_
