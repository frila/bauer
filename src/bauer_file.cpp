#include "bauer_file.hpp"

bauer::bauer_file::bauer_file(std::string _path) : path(_path) {
  file.open(path, std::ifstream::in | std::ios::ate);
  
  if(!file.is_open()) {
    throw bauer::bauer_file_exception("file not found"); 
  }

  size = file.tellg();
  chunks = size/chunk_size + 1;
}

std::string bauer::bauer_file::get_path() {
  return path;
}

bfile_size bauer::bauer_file::get_size() {
  return size;
}

bauer::bauer_file::~bauer_file() {}