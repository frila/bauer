#ifndef BAUER_TCP_CONN_HPP
#define BAUER_TCP_CONN_HPP

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>

namespace bauer {
  class bauer_tcp_conn
  {    
  public:
    //TODO: Estudar forma de implementar send e receive de maneira correta
    ssize_t send() {
      return 0;
    }
    //TODO: mudar tipo de retorno 
    ssize_t recv() {
      return 0;
    }

    bauer_node tgt;

    bauer_tcp_conn();
    ~bauer_tcp_conn();
    
  };
}
#endif