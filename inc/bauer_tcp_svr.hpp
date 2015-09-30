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
    void *data;
  public:
    bauer_tcp_svr(bauer_task_mngr &task_mng,bauer_node &_local,unsigned int maxpending= 3);

    bauer_tcp_svr& force();
    void setup_svr(unsigned int maxpending) throw(bauer_socket_exception);
    bauer_node accept();
    void start();
    void set_data(void *_data);
  };
}

#endif