#ifndef BAUER_TCP_HPP
#define BAUER_TCP_HPP

#include "socket_facade.h"
#include "bauer_types.hpp"
#include "bauer_exception.hpp"

namespace bauer {

bsocket_t tcp_socket() throw(bauer_socket_exception){
  using namespace sckt;

  bsocket_t _socket = 0;
  if ( (_socket = socket(_AF_INET, _SOCK_STREAM,_IPPROTO_TCP)) < 0) {
      throw bauer_socket_exception();
  }
  return _socket;
}

}

#endif