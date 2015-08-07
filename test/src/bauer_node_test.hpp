#include "gtest/gtest.h"
#include "bauer_node_test.hpp"

class bauer_node_test : public ::testing::Test {
  protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(bauer_node_test, should_work) {
  EXPECT_TRUE(true);
}
