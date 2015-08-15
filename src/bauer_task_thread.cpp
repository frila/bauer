#include "bauer_task_thread.hpp"

namespace bauer{

  bauer_task_thread::bauer_task_thread( void (*_exec)(bauer_tcp_channel)) : bauer_task_mngr(_exec) {}

  void bauer_task_thread::dispatcher_exec( bauer_tcp_channel remote){
    new std::thread(exec, remote);
  }
}
