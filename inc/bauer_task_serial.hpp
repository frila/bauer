#ifndef BAUER_TASK_SERIAL_HPP
#define BAUER_TASK_SERIAL_HPP

#include "bauer_task_mngr.hpp"
#include "bauer_tcp_channel.hpp"

namespace bauer {

class bauer_task_serial : public bauer_task_mngr
{
public:
  bauer_task_serial( void (*_exec)(bauer_tcp_channel));
  void dispatcher_exec( bauer_tcp_channel channel);
};

}
#endif