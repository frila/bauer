#include "bauer_task_serial.hpp"

namespace bauer {

  bauer_task_serial::bauer_task_serial( void (*_exec)(bauer_tcp_conn)) : bauer_task_mngr(_exec){}

  void bauer_task_serial::dispatcher_exec( bauer_tcp_conn remote){
    exec(remote);
  }


}
