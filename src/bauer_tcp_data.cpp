#include "bauer_tcp_data.hpp"

#include <cstring>

namespace bauer {

bauer_tcp_data::bauer_tcp_data(): size_buffer(1024) {}
bauer_tcp_data::~bauer_tcp_data(){}

size_t bauer_tcp_data::send(char data[], int nbytes, bauer_node remote) throw(bauer_socket_exception)
{
  char *buffer = new char[size_buffer];
  std::memset(buffer,0,sizeof(char)*size_buffer);
  std::memcpy(buffer, data, nbytes*sizeof(char));

  size_t rt;
  if( (rt = sckt::send(remote.get_socket(), data, sizeof(char)*size_buffer, 0)) < 0) {
    throw bauer_socket_exception();
  }

  return rt;
}

size_t bauer_tcp_data::recv(char* &data, bauer_node remote) throw(bauer_socket_exception)
{
  char *buffer = new char[size_buffer];
  size_t rt;
  if ( (rt = sckt::recv(remote.get_socket(), buffer, sizeof(char) * size_buffer, 0)) < 0 ){
    throw bauer_socket_exception();
  }
  data = buffer;
  return rt;
}


} // bauer