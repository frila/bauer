#ifndef BAUER_FILE
#define BAUER_FILE

#include <iostream>
#include <fstream>
#include "bauer_exception.hpp"
#include "bauer_types.hpp"

namespace bauer {
  class bauer_file
  {
  private:
    std::ifstream file;
    std::string path;
    bfile_size size;
    bfile_chunks chunks;

  public:
    bauer_file(std::string path, short chunk_size = 1024);
    ~bauer_file();

    std::string get_path();
    bfile_size get_size();
    short get_chunk_size();
    bfile_chunks get_chunks();
    void open();
  };
}

#endif