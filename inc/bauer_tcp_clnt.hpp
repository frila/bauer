#ifndef BAUER_TCP_CLNT_HPP
#define BAUER_TCP_CLNT_HPP

#include <iostream>
#include "socket_facade.h"
#include "bauer_tcp.hpp"
#include "bauer_node.hpp"
#include "bauer_tcp_conn.hpp"

namespace bauer {

class bauer_tcp_clnt
{
  private:
    bauer_tcp_conn conn;
  public:
    bauer_tcp_clnt();
    ~bauer_tcp_clnt();

    void connect(bauer_node node) throw(bauer_socket_exception);
    size_t send(std::string data);
    size_t recv(std::string &data);
    
};

}
#endif