#ifndef BAUER_TASK_THREAD_HPP
#define BAUER_TASK_THREAD_HPP

#include <thread>
#include "bauer_types.hpp"
#include "bauer_tcp_channel.hpp"
#include "bauer_task_mngr.hpp"

namespace bauer{

  class bauer_task_thread : public bauer_task_mngr
  {
    public:
      bauer_task_thread( void (*_exec)(bauer_tcp_channel));

      void dispatcher_exec( bauer_tcp_channel remote);
  };
}

#endif