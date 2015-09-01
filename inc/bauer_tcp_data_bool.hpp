#ifndef BAUER_TCP_DATA_BOOL_HPP
#define BAUER_TCP_DATA_BOOL_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "bauer_tcp_data.hpp"

namespace bauer {

class bauer_tcp_data_bool : public bauer_tcp_data
{
private:
  bool data;
protected:
  size_t send(bauer_node remote);
  size_t recv(bauer_node remote);

public:
  friend class bauer_tcp_data_file;
  bauer_tcp_data_bool();
  bauer_tcp_data_bool(bool _data);
  ~bauer_tcp_data_bool();
  bool& get();

  bauer_tcp_data_bool& operator=(const bauer_tcp_data_bool &d);
  bauer_tcp_data_bool& operator=(const bool &d);
  
};

} // bauer

#endif