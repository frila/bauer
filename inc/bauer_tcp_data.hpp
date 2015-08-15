#ifndef BAUER_TCP_DATA_HPP
#define BAUER_TCP_DATA_HPP

#include <iostream>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_exception.hpp"

namespace bauer {

class bauer_tcp_data
{
protected:
  const int size_buffer;

  size_t send(char data[], int nbytes, bauer_node remote) throw(bauer_socket_exception);
  size_t recv(char* &data, bauer_node remote) throw(bauer_socket_exception);

  virtual size_t send(bauer_node remote) = 0;
  virtual size_t recv(bauer_node remote) = 0;

  bauer_tcp_data();
  ~bauer_tcp_data();

public:

  friend class bauer_tcp_channel;
};

} // bauer

#endif