#include "bauer_tcp_svr.hpp"

namespace bauer {

  bauer_tcp_svr::bauer_tcp_svr(bauer_task_mngr &_task_mng, bauer_node &_local, unsigned int maxpending) : 
    task_mng(_task_mng), local(_local) 
  {
    pause_flag = false;
    unique_cicle_flag = false;
    if ( local.get_socket() < 0 ) local.set_socket(tcp_socket());
    setup_svr(maxpending);
  }

  bauer_tcp_svr& bauer_tcp_svr::force() {
    local.set_socket( tcp_socket() );
    return *this;
  }

  void bauer_tcp_svr::pause() {
    pause_flag = true;
  }

  void bauer_tcp_svr::setup_svr(unsigned int maxpending) throw(bauer_socket_exception){
    sckt::sockaddr_in addr;

    memset((void *) &addr, 0, sizeof(addr));
    addr.sin_family = sckt::_AF_INET;
    addr.sin_addr.s_addr = sckt::htonl(sckt::_INADDR_ANY); 
    addr.sin_port = sckt::htons(local.get_port());

    if (sckt::bind(local.get_socket(), (sckt::sockaddr *) &addr, sizeof(addr)) < 0){
      throw bauer_socket_exception();
    }

    if (sckt::listen(local.get_socket(), maxpending) < 0){
      throw bauer_socket_exception();
    }
  }

  bauer_node bauer_tcp_svr::accept(){
    bauer_node client_node;
    sckt::sockaddr_in cliAddr;
    sckt::socklen_t cliLen;

    cliLen = sizeof(cliAddr);
    memset(&cliAddr, 0, (size_t) sizeof(cliAddr));

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
  
  void bauer_tcp_svr::start() {
    while (!pause_flag) {
      bauer_node remote = accept();
      bauer_tcp_channel channel(remote);
      channel.data = data;
      task_mng.dispatcher_exec(channel);

      if(unique_cicle){
        unique_cicle = false;
        break;
      }

    }
    pause_flag = false;
  }

  void bauer_tcp_svr::unique_cicle() {
    unique_cicle_flag = true;
  }

  void bauer_tcp_svr::multi_cicle() {
    unique_cicle_flag = false;
  }

  void bauer_tcp_svr::set_data(void *_data)
  {
    data = _data;
  }
}
