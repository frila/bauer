#include "gtest/gtest.h"
#include "bauer_file.hpp"
#include "bauer_exception.hpp"

using namespace bauer;

class bauer_file_test : public ::testing::Test {
  protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};
/*
TEST_F(bauer_file_test, deveria_setar_o_size_corretamente) {
  bauer_file file("../files/valid_path.txt");
  
  EXPECT_EQ(file.get_size(), 26);
}

TEST_F(bauer_file_test, deveria_setar_o_path_corretamente) {
  bauer_file file("../files/valid_path.txt");
  
  EXPECT_EQ(file.get_path(), "../files/valid_path.txt");
}

TEST_F(bauer_file_test, deveria_abrir_o_arquivo_caso_o_path_for_valido) {
  
  EXPECT_NO_THROW({
    bauer_file file("../files/valid_path.txt");
  });
}

TEST_F(bauer_file_test, nao_deveria_abrir_o_arquivo_caso_o_path_seja_invalido) {  
  EXPECT_THROW({
    bauer_file file("../files/invalid_path.txt");
  }, bauer_file_exception);
}

TEST_F(bauer_file_test, quando_o_tamanho_do_chunk_nao_for_passado_deveria_setar_para_1024) {
  bauer_file file("../files/valid_path.txt", 1024);
  EXPECT_EQ(file.get_chunk_size(), 1024);  
}

TEST_F(bauer_file_test, ao_passar_o_chunk_como_argumento_deveria_setar_o_tamanho_do_chunk) {
  bauer_file file("../files/valid_path.txt", 2048);
  EXPECT_EQ(file.get_chunk_size(), 2048);
}*/