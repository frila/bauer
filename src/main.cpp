#include "bauer_node.hpp"
#include "bauer_tcp.hpp"
#include "bauer_tcp_svr.hpp"
#include "bauer_tcp_conn.hpp"
#include "bauer_tcp_clnt.hpp"
#include "bauer_task_serial.hpp"
#include "bauer_task_thread.hpp"
#include "bauer_task_process.hpp"
#include "bauer_task_pool_thread.hpp"


int main(int argc, char const *argv[])
{
  bauer::bauer_task_pool_thread t;
  t.setup_threads(8);
  return 0;
}
