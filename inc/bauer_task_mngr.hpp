#ifndef BAUER_TASK_MNGR_HPP
#define BAUER_TASK_MNGR_HPP

#include <iostream>
#include "bauer_tcp_conn.hpp"

namespace bauer {

class bauer_task_mngr
{
protected:
  void (*exec)(bauer_tcp_conn);
public:
  ~bauer_task_mngr();
  bauer_task_mngr( void (*_exec)(bauer_tcp_conn));
  bauer_task_mngr();
  virtual void dispatcher_exec( bauer_tcp_conn remote) = 0;
};

} // bauer
#endif