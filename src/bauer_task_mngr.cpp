#include "bauer_task_mngr.hpp"

namespace bauer {

  bauer_task_mngr::bauer_task_mngr( void (*_exec)(bauer_tcp_channel)) : exec(_exec)
  {
  }

  bauer_task_mngr::bauer_task_mngr()
  {
  }

  bauer_task_mngr::~bauer_task_mngr()
  {
  }

  void bauer_task_mngr::set_function(void (*_exec)(bauer_tcp_channel)) {
  	exec = _exec;
  }

} // bauer

