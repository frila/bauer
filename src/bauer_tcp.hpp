#ifndef BAUER_TCP_HPP
#define BAUER_TCP_HPP

#include "socket_facade.h"
#include "bauer_types.hpp"

namespace bauer {

bsocket_t tcp_socket() {
  
  using namespace sckt;
  return socket(AF_INET,SOCK_STREAM,0);
}

}

#endif