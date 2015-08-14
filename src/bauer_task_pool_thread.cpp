#include "bauer_task_pool_thread.hpp"

namespace bauer{

  bauer_task_pool_thread::bauer_task_pool_thread() : bauer_task_mngr() {
    setup_threads(8);
  }

  bauer_task_pool_thread::bauer_task_pool_thread( void (*_exec)(bauer_tcp_conn)) : bauer_task_mngr(_exec){
    setup_threads(8);
  }

  void bauer_task_pool_thread::dispatcher_exec( bauer_tcp_conn tgt){
    //TODO: Avaliar o caso que não há mais threads sobrando
    std::unique_lock<std::mutex> lck(mtx);
    queue_clnt.push_back(tgt);
    queue_cond_var.notify_one();
  }

  bauer_tcp_conn bauer_task_pool_thread::wait_client(){
    bauer_tcp_conn tgt;
    std::unique_lock<std::mutex> lck(mtx);
    queue_cond_var.wait(lck);
    if(queue_clnt.size() > 0){
      tgt = queue_clnt.front();
      queue_clnt.pop_front();
    }
    return tgt;
  }

  void bauer_task_pool_thread::function_thread_execute(){
    while(true){
      bauer_tcp_conn tgt = wait_client();
      exec(tgt);
    }
  }

  void bauer_task_pool_thread::setup_threads(int n){
    for(int i = 0; i < n; i++){
      threads.push_back( new std::thread(&bauer_task_pool_thread::function_thread_execute, this) );
    }
  }

}
