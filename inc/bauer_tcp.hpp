#ifndef BAUER_TCP_HPP
#define BAUER_TCP_HPP

#include <iostream>
#include "socket_facade.h"
#include "bauer_types.hpp"
#include "bauer_exception.hpp"

namespace bauer {

  bsocket_t tcp_socket() throw(bauer_socket_exception);

}

#endif