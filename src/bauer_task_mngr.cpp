#include "bauer_task_mngr.hpp"

namespace bauer {

  bauer_task_mngr::bauer_task_mngr( void (*_exec)(bauer_tcp_conn)) : exec(_exec)
  {
  }

  bauer_task_mngr::bauer_task_mngr()
  {
  }

  bauer_task_mngr::~bauer_task_mngr()
  {
  }


} // bauer

