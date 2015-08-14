#ifndef BAUERT_TCP_SVR
#define BAUERT_TCP_SVR 

#include <iostream>
#include <string.h>
#include "socket_facade.h"
#include "bauer_node.hpp"
#include "bauer_types.hpp"
#include "bauer_tcp.hpp"
#include "bauer_task_mngr.hpp"

namespace bauer {  
  class bauer_tcp_svr
  {
  private:
    bauer_node &local;
    bauer_task_mngr &task_mng;
  public:
    bauer_tcp_svr(bauer_task_mngr &task_mng,bauer_node &_local);

    void force();
    void setup_svr() throw(bauer_socket_exception);
    bauer_node accept();
    void start();
  };
}

#endif