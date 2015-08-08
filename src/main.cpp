#include "bauer_node.hpp"
#include "bauer_tcp.hpp"
#include "bauer_tcp_svr.hpp"
#include "bauer_tcp_conn.hpp"
#include "bauer_tcp_clnt.hpp"
#include "bauer_task_serial.hpp"
#include "bauer_task_thread.hpp"
#include "bauer_task_process.hpp"
#include "bauer_task_pool_thread.hpp"
#include "bauer_exception.hpp"

using namespace bauer;

int main(int argc, char const *argv[])
{
  throw bauer_socket_exception();
}


//docker run -d --name="drone" -p 8081:8081 -v /var/lib/drone/ -v /var/run/docker.sock:/var/run/docker.sock -v /opt/docker/droneio/drone.sqlite:/var/lib/drone/drone.sqlite -v /opt/docker/droneio:/var/lib/drone faustofjunqueira/drone /usr/local/bin/droned --config=/var/lib/drone/drone.toml