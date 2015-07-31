#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include <string.h>
#include "socket_facade.h"
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
      /* Create a local communication endpoint */
      if ( _local.get_socket() < 0 ) _local.set_socket(tcp_socket());
      local = _local;

    }

    ~bauer_tcp_svr();

    void force() {
      local.set_socket( tcp_socket() );
    }

    void setup_svr(){
      sckt::sockaddr_in addr; /* local address */

      /* Setup the local address */
      memset((void *) &addr, 0, sizeof(addr)); /* zero out structure */
      addr.sin_family = sckt::_AF_INET; /* Internet address family */
      addr.sin_addr.s_addr = sckt::htonl(sckt::_INADDR_ANY); /* any incoming interface */
      addr.sin_port = sckt::htons(local.get_port()); /* local port */

      /* Bind to the local address */
      if (sckt::bind(local.get_socket(), (sckt::sockaddr *) &addr, sizeof(addr)) < 0){
        throw new int; //TODO: Bind failed
      }

      /* Mark the socket so it will listen for incoming connections */
      // TODO VER MAXPENDING no codigo da Silvana
      if (sckt::listen(local.get_socket(), 3) < 0){
        throw new int; //TODO: Listen faileds
      }

    }



  };
}

#endif