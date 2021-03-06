#include "bauer_task_process.hpp"

namespace bauer{
  bauer_task_process::bauer_task_process( void (*_exec)(bauer_tcp_channel)) : bauer_task_mngr(_exec){}

  void bauer_task_process::dispatcher_exec( bauer_tcp_channel remote){
    //TODO: fork == -1 é erro, fazer exception
    if (!fork()){ // FORK == 0 é o processo filho
      exec(remote);
      exit(0);
    }
    //TODO: fazer waitpid para garatir que o processo principal só termine quando todos os filhos terminaram.
  }
}
