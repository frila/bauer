#ifndef BAUER_TCP_CHANNEL_HPP
#define BAUER_TCP_CHANNEL_HPP

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_exception.hpp"
#include "bauer_tcp_data.hpp"

namespace bauer {


class bauer_tcp_channel
{
private:
  bauer_node tgt;
public:
  bauer_tcp_channel();
  bauer_tcp_channel(bauer_node _tgt);
  ~bauer_tcp_channel();
  size_t send(bauer_tcp_data &data) throw(bauer_socket_exception);
  size_t recv(bauer_tcp_data &data) throw(bauer_socket_exception);
  void set_target(bauer_node _tgt);
  bauer_node& get_target();

};

} // bauer
#endif