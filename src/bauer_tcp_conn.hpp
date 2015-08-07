#ifndef BAUER_TCP_CONN_HPP
#define BAUER_TCP_CONN_HPP

#include <iostream>
#include <string.h>
#include "bauer_node.hpp"
#include "socket_facade.h"

namespace bauer {
  class bauer_tcp_conn
  {
  private:
    bauer_node tgt;
  public:
    
    size_t send(std::string data) throw(bauer_socket_exception){
      const char* data_to_char = data.c_str();
      size_t rt;
	    if( (rt = sckt::send(tgt.get_socket(), data_to_char, strlen(data_to_char), 0)) < 0) {
        throw bauer_socket_exception();
	    }

	    return rt;
    }

    size_t recv(std::string &data) throw(bauer_socket_exception){
      char *buffer = new char[1024];
      size_t rt;
      memset(buffer,0,sizeof(char)*1024);
      if ( (rt = sckt::recv(tgt.get_socket(), buffer, 100, 0)) < 0 ){
        throw bauer_socket_exception();
      }
      data = buffer;
      return rt;
    }

    void set_target(bauer_node _tgt) {
    	tgt = _tgt;
    }

    bauer_node& get_target(){
    	return tgt;
    }

    bauer_tcp_conn() {}
    bauer_tcp_conn( bauer_node _tgt) {
      tgt = _tgt;
    }
    ~bauer_tcp_conn() {}
    
  };
}
#endif