#ifndef BAUER_TCP_HPP
#define BAUER_TCP_HPP

#include <sys/socket.h>
#include "bauer_types.hpp"

namespace bauer {

bsocket_t tcp_socket() {
  return socket(AF_INET,SOCK_STREAM,0);
}

}

#endif