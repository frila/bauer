#ifndef BAUER_TASK_PROCESS_HPP
#define BAUER_TASK_PROCESS_HPP

#include <stdlib.h>
#include <unistd.h>
#include "bauer_types.hpp"
#include "bauer_tcp_conn.hpp"
#include "bauer_task_mngr.hpp"

namespace bauer{

  class bauer_task_process : public bauer_task_mngr
  {
    public:
      bauer_task_process( void (*_exec)(bauer_tcp_conn));
      void dispatcher_exec( bauer_tcp_conn remote);
  };
}

#endif