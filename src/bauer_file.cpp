#include "bauer_file.hpp"

bauer::bauer_file::bauer_file(std::string _path, short _chunk_size) {
  path = _path;
  chunk_size = _chunk_size;

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

short bauer::bauer_file::get_chunk_size() {
  return chunk_size;
}

bfile_chunks bauer::bauer_file::get_chunks() {
  return chunks;
}

bauer::bauer_file::~bauer_file() {}