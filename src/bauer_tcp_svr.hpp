#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_types.hpp"
#include "bauer_tcp.hpp"

namespace bauer {
  template<class Tasker>
  class bauer_tcp_svr
  {
  private:
    bauer_node local;
    Tasker task_mng;
  public:

    bauer_tcp_svr(bauer_node _local, void (*_exec)(bauer_node)) {

      if ( _local.get_socket() < 0 ) _local.set_socket(tcp_socket());
      Tasker _task_mng(_exec); 
      local = _local;
      task_mng = _task_mng;

      setup_svr();
    }

    ~bauer_tcp_svr();

    void force() {
      local.set_socket( tcp_socket() );
    }

    void setup_svr(){
      sckt::sockaddr_in addr;

      
      memset((void *) &addr, 0, sizeof(addr));
      addr.sin_family = sckt::_AF_INET;
      addr.sin_addr.s_addr = sckt::htonl(sckt::_INADDR_ANY); 
      addr.sin_port = sckt::htons(local.get_port());

      if (sckt::bind(local.get_socket(), (sckt::sockaddr *) &addr, sizeof(addr)) < 0){
        throw new int; //TODO: Bind failed
      }

      // TODO VER MAXPENDING no codigo da Silvana
      if (sckt::listen(local.get_socket(), 3) < 0){
        throw new int; //TODO: Listen faileds
      }

    }

    bauer_node accept(){
      bauer_node client_node;
      sckt::sockaddr_in cliAddr;
      unsigned int cliLen;

      cliLen = sizeof(cliAddr);

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
        bauer_node remote = accept();
        task_mng.dispatcher_exec(remote);
      }
    }

  };
}

#endif