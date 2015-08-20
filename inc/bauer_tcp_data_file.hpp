#ifndef BAUER_TCP_DATA_FILE_HPP
#define BAUER_TCP_DATA_FILE_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include "bauer_exception.hpp"
#include "bauer_tcp_data.hpp"
#include "bauer_tcp_data_int.hpp"

namespace bauer {

class bauer_tcp_data_file : public bauer_tcp_data
{
private:
  std::fstream fs;
  std::string path;
  std::streampos size;
  char *bfs;//buffer send
  std::list<char*> bfr; // buffer recv
protected:
  size_t send(bauer_node remote);
  size_t recv(bauer_node remote);

public:
  
  bauer_tcp_data_file(std::string _path);
  ~bauer_tcp_data_file();
};

  
} // bauer

#endif