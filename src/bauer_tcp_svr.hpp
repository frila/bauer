#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include "bauer_tcp.hpp"

namespace bauer {
  class bauer_tcp_svr
  {
  private:
    bauer_node local;
  public:
    void start() {

    }

    bauer_tcp_svr(bauer_node _local) {

      if ( _local.get_socket() < 0 ) _local.set_socket(tcp_socket());

    }

    ~bauer_tcp_svr();

    void force() {
      local.set_socket( tcp_socket() );
    }
  };
}

#endif