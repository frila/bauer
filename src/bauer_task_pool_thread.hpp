#ifndef BAUER_TASK_POOL_THREAD_HPP
#define BAUER_TASK_POOL_THREAD_HPP

#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "bauer_tcp_conn.hpp"

namespace bauer{


  class bauer_task_pool_thread
  {
    private:
      void (*exec)(bauer_tcp_conn);
      std::list<std::thread*> threads;
      std::list<bauer_tcp_conn> queue_clnt;
      std::mutex mtx;
      std::condition_variable queue_cond_var;
    public:
      bauer_task_pool_thread() {
        setup_threads(8);
      }

      bauer_task_pool_thread( void (*_exec)(bauer_tcp_conn)){
        exec = _exec;
        setup_threads(8);
      }
      ~bauer_task_pool_thread() {}

      void dispatcher_exec( bauer_tcp_conn tgt){
        //TODO: Avaliar o caso que não há mais threads sobrando
        std::unique_lock<std::mutex> lck(mtx);
        queue_clnt.push_back(tgt);
        queue_cond_var.notify_one();
      }

      bauer_tcp_conn wait_client(){
        bauer_tcp_conn tgt;
        std::unique_lock<std::mutex> lck(mtx);
        queue_cond_var.wait(lck);
        if(queue_clnt.size() > 0){
          tgt = queue_clnt.front();
          queue_clnt.pop_front();
        }
        return tgt;
      }

      void function_thread_execute(){
        while(true){
          bauer_tcp_conn tgt = wait_client();
          exec(tgt);
        }
      }
    
      void setup_threads(int n){
        for(int i = 0; i < n; i++){
          threads.push_back( new std::thread(&bauer_task_pool_thread::function_thread_execute, this) );
        }
      }
    
  };

}

#endif