#ifndef BAUER_TCP_HPP
#define BAUER_TCP_HPP

#include "socket_facade.h"
#include "bauer_types.hpp"

namespace bauer {

bsocket_t tcp_socket() {
  using namespace sckt;

  bsocket_t _socket = 0;
  if ( (_socket = socket(_AF_INET, _SOCK_STREAM,_IPPROTO_TCP)) < 0) {
      throw new int; //TODO: Can't to create the socket
  }
  return _socket;
}

}

#endif