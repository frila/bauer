#include <iostream>
#include "bauer.h"

using namespace bauer;

void exec(bauer_tcp_conn remote){
  std::cout << "Server - Client Connectado" << std::endl;
  std::string a;
  while(true){
    remote.recv(a);
    std::cout << std::string("[Server] - ") << a << std::endl;
    a = "Recebido"; 
    remote.send(a);
  }
}

//g++ -std=c++11 -o bin/server programs_test/simple_chat/server.cpp -Iinc -pthread -Wall -I src -lbauer
int main(int argc, char const *argv[])
{
  bauer_task_process tasker(exec);
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
  bauer_tcp_svr server(tasker, server_node);
  server.start();

  return 0;
}