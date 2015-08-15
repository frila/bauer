#include "bauer_tcp_clnt.hpp"

namespace bauer {

  bauer_tcp_clnt::bauer_tcp_clnt() {}
  bauer_tcp_clnt::~bauer_tcp_clnt() {}

  void bauer_tcp_clnt::connect(bauer_node &node) throw(bauer_socket_exception){
    sckt::sockaddr_in server;

    channel.set_target(node);
    server.sin_addr.s_addr = sckt::inet_addr(channel.get_target().get_ip().c_str());
    server.sin_family = sckt::_AF_INET;
    server.sin_port = sckt::htons(channel.get_target().get_port());

    channel.get_target().set_socket(tcp_socket());

    if (sckt::connect((bsocket_t) channel.get_target().get_socket() , (sckt::sockaddr *)&server , (sckt::socklen_t) sizeof(server)) < 0)
    {
      throw bauer_socket_exception();
    }
  }

  size_t bauer_tcp_clnt::send(bauer_tcp_data &data)
  {

    return channel.send(data);
  }

  size_t bauer_tcp_clnt::recv(bauer_tcp_data &data)
  {
    return channel.recv(data);
  }

}
