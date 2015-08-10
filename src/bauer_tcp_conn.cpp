#include "bauer_tcp_conn.hpp"

namespace bauer {
  
  size_t bauer_tcp_conn::send(std::string data) throw(bauer_socket_exception){
    const char* data_to_char = data.c_str();
    size_t rt;
    if( (rt = sckt::send(tgt.get_socket(), data_to_char, strlen(data_to_char), 0)) < 0) {
      throw bauer_socket_exception();
    }

    return rt;
  }

  size_t bauer_tcp_conn::recv(std::string &data) throw(bauer_socket_exception){
    char *buffer = new char[1024];
    size_t rt;
    memset(buffer,0,sizeof(char)*1024);
    if ( (rt = sckt::recv(tgt.get_socket(), buffer, 100, 0)) < 0 ){
      throw bauer_socket_exception();
    }
    data = buffer;
    return rt;
  }

  void bauer_tcp_conn::set_target(bauer_node _tgt) {
  	tgt = _tgt;
  }

  bauer_node& bauer_tcp_conn::get_target(){
  	return tgt;
  }

  bauer_tcp_conn::bauer_tcp_conn() {}
  bauer_tcp_conn::bauer_tcp_conn( bauer_node _tgt) {
    tgt = _tgt;
  }
  bauer_tcp_conn::~bauer_tcp_conn() {}
  
}
