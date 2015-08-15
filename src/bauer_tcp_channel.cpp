#include "bauer_tcp_channel.hpp"

namespace bauer {


bauer_tcp_channel::bauer_tcp_channel()
{
}

bauer_tcp_channel::bauer_tcp_channel(bauer_node _tgt) : tgt(_tgt)
{
}

bauer_tcp_channel::~bauer_tcp_channel()
{
}

size_t bauer_tcp_channel::send(bauer_tcp_data &data) throw(bauer_socket_exception)
{
  return data.send(tgt);
}

size_t bauer_tcp_channel::recv(bauer_tcp_data &data) throw(bauer_socket_exception)
{
  return data.recv(tgt);
}

void bauer_tcp_channel::set_target(bauer_node _tgt)
{
  tgt = _tgt;
}

bauer_node& bauer_tcp_channel::get_target()
{
  return tgt;
}

} // bauer