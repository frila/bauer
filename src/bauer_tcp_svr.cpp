#include "bauer_tcp_svr.hpp"

namespace bauer {
  
  template<class Tasker>
  bauer_tcp_svr<Tasker>::~bauer_tcp_svr() {}
  
  template<class Tasker>
  bauer_tcp_svr<Tasker>::bauer_tcp_svr() {}

  template<class Tasker>
  bauer_tcp_svr<Tasker>::bauer_tcp_svr(bauer_node _local, void (*_exec)(bauer_tcp_conn)) {

    if ( _local.get_socket() < 0 ) _local.set_socket(tcp_socket());
    local = _local;
    task_mng = new Tasker(_exec);

    setup_svr();
  }

  template<class Tasker>
  void bauer_tcp_svr<Tasker>::force() {
    local.set_socket( tcp_socket() );
  }

  template<class Tasker>
  void bauer_tcp_svr<Tasker>::setup_svr() throw(bauer_socket_exception){
    sckt::sockaddr_in addr;

    
    memset((void *) &addr, 0, sizeof(addr));
    addr.sin_family = sckt::_AF_INET;
    addr.sin_addr.s_addr = sckt::htonl(sckt::_INADDR_ANY); 
    addr.sin_port = sckt::htons(local.get_port());

    if (sckt::bind(local.get_socket(), (sckt::sockaddr *) &addr, sizeof(addr)) < 0){
      throw bauer_socket_exception();
    }

    // TODO VER MAXPENDING no codigo da Silvana
    if (sckt::listen(local.get_socket(), 3) < 0){
      throw bauer_socket_exception();
    }

  }

  template<class Tasker>
  bauer_node bauer_tcp_svr<Tasker>::accept(){
    bauer_node client_node;
    sckt::sockaddr_in cliAddr;
    unsigned int cliLen;

    cliLen = sizeof(cliAddr);

    bsocket_t accept_d = sckt::accept(local.get_socket(), (sckt::sockaddr*) &cliAddr, &cliLen);

    if ( accept_d < 0) {
      throw bauer_socket_exception();
    } else {
      client_node.set_socket(accept_d);
    }

    client_node.set_ip(sckt::inet_ntoa(cliAddr.sin_addr));
    client_node.set_port(cliAddr.sin_port);
    return client_node;
  }
  
  template<class Tasker>
  void bauer_tcp_svr<Tasker>::start() {
    while (true) {
      bauer_node remote = accept();
      bauer_tcp_conn conn(remote);
      task_mng->dispatcher_exec(remote);
    }
  }

}