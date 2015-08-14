#ifndef BAUER_TASK_SERIAL_HPP
#define BAUER_TASK_SERIAL_HPP

#include "bauer_tcp_conn.hpp"
#include "bauer_task_mngr.hpp"

namespace bauer {

class bauer_task_serial : public bauer_task_mngr
{
public:
  bauer_task_serial( void (*_exec)(bauer_tcp_conn));
  void dispatcher_exec( bauer_tcp_conn remote);
};

}
#endif