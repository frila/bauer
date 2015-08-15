#ifndef BAUER_TCP_CLNT_HPP
#define BAUER_TCP_CLNT_HPP

#include <iostream>
#include "socket_facade.h"
#include "bauer_tcp.hpp"
#include "bauer_node.hpp"
#include "bauer_tcp_channel.hpp"

namespace bauer {

class bauer_tcp_clnt
{
  private:
    bauer_tcp_channel channel;
  public:
    bauer_tcp_clnt();
    ~bauer_tcp_clnt();

    void connect(bauer_node &node) throw(bauer_socket_exception);
    size_t send(bauer_tcp_data &data);
    size_t recv(bauer_tcp_data &data);
    
};

}
#endif