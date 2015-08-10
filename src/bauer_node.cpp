#include "bauer_node.hpp"

namespace bauer {

  bauer_node::bauer_node() {
    socket = -1;
  }

  bauer_node::bauer_node(bsocket_t _socket, bauer_ip _ip, bauer_port _port) {
    socket = _socket;
    ip = _ip;
    port = _port;
  }

  bauer_node::bauer_node(bauer_ip _ip, bauer_port _port) {
    socket = -1;
    ip = _ip;
    port = _port;
  }

  bsocket_t bauer_node::get_socket() {
    return socket;
  }

  bauer_ip bauer_node::get_ip() {
    return ip;
  }

  bauer_port bauer_node::get_port() {
    return port;
  }

  void bauer_node::set_socket(bsocket_t val) {
    socket = val;
  }

  void bauer_node::set_ip(bauer_ip val) {
    ip = val;
  }

  void bauer_node::set_port(bauer_port val) {
    port = val;
  }

  bauer_node::~bauer_node() {}

}
