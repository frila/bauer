#ifndef BAUER_TASK_POOL_THREAD_HPP
#define BAUER_TASK_POOL_THREAD_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include "bauer_tcp_conn.hpp"
#include "bauer_task_mngr.hpp"

namespace bauer{


  class bauer_task_pool_thread : public bauer_task_mngr
  {
    private:
      std::list<std::thread*> threads;
      std::list<bauer_tcp_conn> queue_clnt;
      std::mutex mtx;
      std::condition_variable queue_cond_var;
    public:
      bauer_task_pool_thread();
      bauer_task_pool_thread( void (*_exec)(bauer_tcp_conn));

      void dispatcher_exec( bauer_tcp_conn tgt);
      bauer_tcp_conn wait_client();
      void function_thread_execute();
      void setup_threads(int n);
  };

}

#endif