#include "bauer_tcp_data_int.hpp"

namespace bauer {

bauer_tcp_data_int::~bauer_tcp_data_int()
{

}

bauer_tcp_data_int::bauer_tcp_data_int() : bauer_tcp_data()
{

}

bauer_tcp_data_int::bauer_tcp_data_int(int _data) : bauer_tcp_data(), data(_data)
{
}

int& bauer_tcp_data_int::get()
{
  return data;
}

size_t bauer_tcp_data_int::send(bauer_node remote)
{
  int n = 11;// max int contem 10 caracteres TODO: fazer constante
  char *d = new char[n];
  std::memset(d,0,sizeof(char)*n);
  std::sprintf(d, "%d", data);
  return bauer_tcp_data::send(d,remote);
}

size_t bauer_tcp_data_int::recv(bauer_node remote)
{
  char *dt;
  size_t b = bauer_tcp_data::recv(dt, remote);
  data = std::atoi(dt);
  return b;
}

bauer_tcp_data_int& bauer_tcp_data_int::operator=(const bauer_tcp_data_int &d)
{
  data = d.data;
  return *this;
}

bauer_tcp_data_int& bauer_tcp_data_int::operator=(const int &d)
{
  data = d;
  return *this;
}

} // bauer