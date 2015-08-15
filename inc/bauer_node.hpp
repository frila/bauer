#ifndef BAUER_NODE_HPP
#define BAUER_NODE_HPP

#include <iostream>
#include "bauer_types.hpp"

namespace bauer {
  class bauer_node
  {
  private:
    bsocket_t socket;
    //TODO: transformar bauer_ip em classe, atualmente é string declarada em bauer_types.hpp
    bauer_ip ip;
    bauer_port port;
  public:
    bauer_node();
    bauer_node(bsocket_t _socket, bauer_ip _ip, bauer_port _port);
    bauer_node(bauer_ip _ip, bauer_port _port);
    ~bauer_node();

    bsocket_t get_socket();
    bauer_ip get_ip();
    bauer_port get_port();
    void set_socket(bsocket_t val);
    void set_ip(bauer_ip val);
    void set_port(bauer_port val);
  };
}

#endif