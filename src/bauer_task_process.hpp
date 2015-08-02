#ifndef BAUER_TASK_PROCESS_HPP
#define BAUER_TASK_PROCESS_HPP

#include <stdlib.h>
#include <unistd.h>
#include "bauer_types.hpp"
#include "bauer_tcp_conn.hpp"

namespace bauer{

  class bauer_task_process
  {
    private:
      void (*exec)(bauer_tcp_conn);
    public:
      bauer_task_process() {}
      bauer_task_process( void (*_exec)(bauer_tcp_conn)){
        exec = _exec;
      }
      ~bauer_task_process() {}

      void dispatcher_exec( bauer_tcp_conn remote){
        //TODO: fork == -1 é erro, fazer exception
        if (!fork()){ // FORK == 0 é o processo filho
          exec(remote);
          exit(0);
        }
        //TODO: fazer waitpid para garatir que o processo principal só termine quando todos os filhos terminaram.
      }
  };
}

#endif