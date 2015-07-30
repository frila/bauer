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
    bauer_node() {
      socket = -1;
    }

    bauer_node(bsocket_t _socket, bauer_ip _ip, bauer_port _port) {
      this->socket = _socket;
      this->ip = _ip;
      this->port = _port;
    }

    bauer_node(bauer_ip _ip, bauer_port _port) : bauer_node() {
      this->ip = _ip;
      this->port = _port;
    }

    bsocket_t get_socket() {
      return socket;
    }

    bauer_ip get_ip() {
      return ip;
    }

    bauer_port get_port() {
      return port;
    }

    void set_socket(bsocket_t val) {
      socket = val;
    }

    void set_ip(bauer_ip val) {
      ip = val;
    }

    void set_port(bauer_port val) {
      port = val;
    }

    ~bauer_node() {}
  };
}

#endif