#ifndef BAUER_TCP_CONN_HPP
#define BAUER_TCP_CONN_HPP

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_exception.hpp"

namespace bauer {
  class bauer_tcp_conn
  {
  private:
    bauer_node tgt;
  public:
    bauer_tcp_conn();
    bauer_tcp_conn( bauer_node _tgt);
    ~bauer_tcp_conn();
    
    size_t send(std::string data) throw(bauer_socket_exception);
    size_t recv(std::string &data) throw(bauer_socket_exception);
    void set_target(bauer_node _tgt);
    bauer_node& get_target();
  };
}
#endif