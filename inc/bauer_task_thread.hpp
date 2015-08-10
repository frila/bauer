#ifndef BAUER_TASK_THREAD_HPP
#define BAUER_TASK_THREAD_HPP

#include "bauer_types.hpp"
#include "bauer_tcp_conn.hpp"
#include <thread>

namespace bauer{

  class bauer_task_thread
  {
    private:
      void (*exec)(bauer_tcp_conn);
    public:
      bauer_task_thread();
      bauer_task_thread( void (*_exec)(bauer_tcp_conn));
      ~bauer_task_thread();

      void dispatcher_exec( bauer_tcp_conn remote);
  };
}

#endif