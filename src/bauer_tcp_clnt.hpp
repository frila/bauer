#ifndef BAUER_TCP_CLNT_HPP
#define BAUER_TCP_CLNT_HPP

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
    bauer_tcp_clnt() {}
    ~bauer_tcp_clnt() {}

    void connect(bauer_node node){
      sckt::sockaddr_in server;

      conn.set_target(node);
      server.sin_addr.s_addr = sckt::inet_addr(conn.get_target().get_ip().c_str());
      server.sin_family = sckt::_AF_INET;
      server.sin_port = sckt::htons(conn.get_target().get_port());

      conn.get_target().set_socket(tcp_socket());

      if (sckt::connect((bsocket_t) conn.get_target().get_socket() , (sckt::sockaddr *)&server , (sckt::socklen_t) sizeof(server)) < 0)
      {
          throw new int; //TOOD Can't to connect with "+node->ip
      }
    }

    size_t send(std::string data)
    {
      return conn.send(data);
    }

    size_t recv(std::string &data)
    {
      return conn.recv(data);
    }
    
};

}
#endif