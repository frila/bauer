#include "bauer_tcp_data_string.hpp"

namespace bauer {

bauer_tcp_data_string::~bauer_tcp_data_string()
{

}

bauer_tcp_data_string::bauer_tcp_data_string() : bauer_tcp_data()
{

}

bauer_tcp_data_string::bauer_tcp_data_string(std::string _data) : bauer_tcp_data(), data(_data)
{
}

bauer_tcp_data_string::bauer_tcp_data_string(char* _data) : bauer_tcp_data(), data(std::string(_data))
{
}

std::string& bauer_tcp_data_string::get()
{
  return data;
}

size_t bauer_tcp_data_string::send(bauer_node remote)
{
  char *d = const_cast<char *>(data.c_str());
  return bauer_tcp_data::send(d,100,remote);
}

size_t bauer_tcp_data_string::recv(bauer_node remote)
{
  char *dt;
  size_t b = bauer_tcp_data::recv(dt, remote);
  data = dt;
  return b;
}

bauer_tcp_data_string& bauer_tcp_data_string::operator=(const bauer_tcp_data_string &d)
{
  data = d.data;
  return *this;
}

bauer_tcp_data_string& bauer_tcp_data_string::operator=(const std::string &d)
{
  data = d;
  return *this;
}

bauer_tcp_data_string& bauer_tcp_data_string::operator=(const char d[])
{
  data = std::string(d);
  return *this;
}

} // bauer