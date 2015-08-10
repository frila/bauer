#include "gtest/gtest.h"
#include "bauer.h"

using namespace bauer;

class bauer_tcp_test : public ::testing::Test {
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(bauer_tcp_test, criacao_socket_tcp){
  bsocket_t socket = tcp_socket();
  ASSERT_GT(socket, 0);
}