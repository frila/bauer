#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_types.hpp"
#include "bauer_tcp.hpp"

namespace bauer {
  class bauer_tcp_svr
  {
  private:
    bauer_node local;
  public:

    bauer_tcp_svr(bauer_node _local) {
      /* Create a local communication endpoint */
      if ( _local.get_socket() < 0 ) _local.set_socket(tcp_socket());
      local = _local;

      setup_svr();
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

    bauer_node accept(){
      bauer_node client_node;
      sckt::sockaddr_in cliAddr; /* client address */
      unsigned int cliLen; /* length of client address data structure */

      /* Set the size of the in-out parameter */
      cliLen = sizeof(cliAddr);

      /* Wait for a client to connect */
      bsocket_t accept_d = sckt::accept(local.get_socket(), (sckt::sockaddr*) &cliAddr, &cliLen);

      if ( accept_d < 0) {
          throw new int; //TODO "Accept failed
      } else {
        client_node.set_socket(accept_d);
      }

      client_node.set_ip(sckt::inet_ntoa(cliAddr.sin_addr));
      client_node.set_port(cliAddr.sin_port);
      return client_node;
    }

    void start() {
      while (true) {
        //aceitando conexão de um nó remoto
        bauer_node remote = accept();
        //TODO: Implementar o Task Manager
        
      }
    }

  };
}

#endif