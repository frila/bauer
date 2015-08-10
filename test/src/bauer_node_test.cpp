#include "gtest/gtest.h"
#include "bauer.h"

using namespace bauer;

class bauer_node_test : public ::testing::Test {
  protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(bauer_node_test, construtor_vazio_nao_deveria_inicializar_o_socket) {
  bauer_node node;
  ASSERT_EQ(node.get_socket(), -1);
}

TEST_F(bauer_node_test, construtor_passando_ip_porta_deveria_inicializar_ip_e_porta) {
  bauer_node node("127.0.0.1", 9999);
  ASSERT_EQ(node.get_ip(), "127.0.0.1");
  ASSERT_EQ(node.get_port(), 9999);
}

TEST_F(bauer_node_test, construtor_passando_ip_porta_nao_deveria_inicializar_socket) {
  bauer_node node("127.0.0.1", 9999);
  ASSERT_EQ(node.get_socket(), -1);
}

TEST_F(bauer_node_test, construtor_passando_ip_porta_e_socket_deveria_inicializar_todos_os_atributos) {
  bauer_node node(tcp_socket(), "127.0.0.1", 9999);
  ASSERT_EQ(node.get_ip(), "127.0.0.1");
  ASSERT_EQ(node.get_port(), 9999);
  ASSERT_NE(node.get_socket(), -1);
}