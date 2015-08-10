#include "bauer_tcp.hpp"

namespace bauer {

using namespace sckt;

  bsocket_t tcp_socket() throw(bauer_socket_exception){

    bsocket_t _socket = 0;
    if ( (_socket = socket(_AF_INET, _SOCK_STREAM,_IPPROTO_TCP)) < 0) {
        throw bauer_socket_exception();
    }
    return _socket;
  }

}
