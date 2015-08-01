#include <iostream>
#include "bauer_tcp.hpp"
#include "bauer_tcp_svr.hpp"
#include "bauer_node.hpp"
#include "bauer_tcp_conn.hpp"
#include "bauer_task_serial.hpp"

using namespace bauer;

void exec(bauer_tcp_conn remote){
  std::cout << "Server - Client Connectado" << std::endl;
  std::string a;
  while(true){
    remote.recv(a);
    std::cout << std::string("[Server] - ") << a << std::endl;
    std::cin >> a; 
    remote.send(a);
  }
}

//g++ -o bin/server src/server.cpp -pthread -Wall
int main(int argc, char const *argv[])
{
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9997);
  bauer_tcp_svr<bauer_task_serial> server(server_node, exec);
  server.start();

  return 0;
}