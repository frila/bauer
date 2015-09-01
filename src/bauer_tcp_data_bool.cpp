#include "bauer_tcp_data_bool.hpp"

namespace bauer {

bauer_tcp_data_bool::~bauer_tcp_data_bool()
{

}

bauer_tcp_data_bool::bauer_tcp_data_bool() : bauer_tcp_data()
{

}

bauer_tcp_data_bool::bauer_tcp_data_bool(bool _data) : bauer_tcp_data(), data(_data)
{
}

bool& bauer_tcp_data_bool::get()
{
  return data;
}

size_t bauer_tcp_data_bool::send(bauer_node remote)
{
  int n = 1;// UM unico bit
  char *d = new char[n];
  if (data) *d = 1;
  else *d = 0;
  return bauer_tcp_data::send(d,remote,n);
}

size_t bauer_tcp_data_bool::recv(bauer_node remote)
{
  char *dt;
  size_t b = bauer_tcp_data::recv(dt, remote);
  data = *dt == 1;
  return b;
}

bauer_tcp_data_bool& bauer_tcp_data_bool::operator=(const bauer_tcp_data_bool &d)
{
  data = d.data;
  return *this;
}

bauer_tcp_data_bool& bauer_tcp_data_bool::operator=(const bool &d)
{
  data = d;
  return *this;
}

} // bauer