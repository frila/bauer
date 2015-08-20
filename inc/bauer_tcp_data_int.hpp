#ifndef BAUER_TCP_DATA_INT_HPP
#define BAUER_TCP_DATA_INT_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "bauer_tcp_data.hpp"

namespace bauer {

class bauer_tcp_data_int : public bauer_tcp_data
{
private:
  int data;
protected:
  size_t send(bauer_node remote);
  size_t recv(bauer_node remote);

public:
  friend class bauer_tcp_data_file;
  bauer_tcp_data_int();
  bauer_tcp_data_int(int _data);
  ~bauer_tcp_data_int();
  int& get();

  bauer_tcp_data_int& operator=(const bauer_tcp_data_int &d);
  bauer_tcp_data_int& operator=(const int &d);
  
};

} // bauer

#endif