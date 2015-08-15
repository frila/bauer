#include "gtest/gtest.h"
#include <iostream>
#include "bauer.h"

using namespace bauer;

class bauer_tcp_data_string_test : public ::testing::Test {
  protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(bauer_tcp_data_string_test, construtor_vazio_data_vazio) {
  bauer_tcp_data_string data;
  int r = data.get().compare("");
  ASSERT_EQ(r, 0);
}

TEST_F(bauer_tcp_data_string_test, construtor_com_string_contem_mesma_string) {
  bauer_tcp_data_string data(std::string("TESTE"));
  int r = data.get().compare("TESTE");
  ASSERT_EQ(r, 0);
}

TEST_F(bauer_tcp_data_string_test, construtor_com_char_ptr_contem_mesma_string) {
  bauer_tcp_data_string data("TESTE");
  int r = data.get().compare("TESTE");
  ASSERT_EQ(r, 0);
}

TEST_F(bauer_tcp_data_string_test, atribuicao_de_string) {
  bauer_tcp_data_string data = std::string("TESTE");
  int r = data.get().compare("TESTE");
  ASSERT_EQ(r, 0);
}

TEST_F(bauer_tcp_data_string_test, atribuicao_de_char_ptr) {
  bauer_tcp_data_string data = "TESTE";
  int r = data.get().compare("TESTE");
  ASSERT_EQ(r, 0);
}
TEST_F(bauer_tcp_data_string_test, cast_to_string) {
  bauer_tcp_data_string data = "TESTE";
  std::string st = static_cast<std::string>(data);
  int r = st.compare("TESTE");
  ASSERT_EQ(r, 0);
}
