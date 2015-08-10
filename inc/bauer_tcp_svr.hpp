#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_types.hpp"
#include "bauer_tcp.hpp"
#include "bauer_tcp_conn.hpp"

namespace bauer {
  template<class Tasker>
  class bauer_tcp_svr
  {
  private:
    bauer_node local;
    Tasker *task_mng;
  public:
    ~bauer_tcp_svr();
    bauer_tcp_svr();

    bauer_tcp_svr(bauer_node _local, void (*_exec)(bauer_tcp_conn));

    void force();
    void setup_svr() throw(bauer_socket_exception);
    bauer_node accept();
    void start();
  };
}

#endif