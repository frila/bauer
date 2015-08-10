#include "bauer_task_thread.hpp"

namespace bauer{

  bauer_task_thread::bauer_task_thread() {}
  bauer_task_thread::bauer_task_thread( void (*_exec)(bauer_tcp_conn)){
    exec = _exec;
  }
  bauer_task_thread::~bauer_task_thread() {}

  void bauer_task_thread::dispatcher_exec( bauer_tcp_conn remote){
    new std::thread(exec, remote);
  }
}
