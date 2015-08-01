#ifndef BAUER_TASK_SERIAL_HPP
#define BAUER_TASK_SERIAL_HPP

#include "bauer_tcp_conn.hpp"

namespace bauer {

class bauer_task_serial
{
private:
  bauer_task_function exec;
public:
  bauer_task_serial() {}
  bauer_task_serial( bauer_task_function _exec){
    exec = _exec;
  }
  ~bauer_task_serial() {}

  void dispatcher_exec( bauer_tcp_conn remote){
    exec(remote);
  }

};

}
#endif