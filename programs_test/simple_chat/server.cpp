#include <iostream>
#include "bauer.h"

using namespace bauer;

void exec(bauer_tcp_channel remote){
  std::cout << "Server - Client Connectado" << std::endl;
  bauer_tcp_data_string data;
  while(true){
    remote.recv(data);
    std::cout << std::string("[Server] - ") << static_cast<std::string>(data) << std::endl;
    data = "Recebido"; 
    remote.send(data);
  }
}

//g++ -std=c++11 -o bin/server programs_test/simple_chat/server.cpp -Iinc -pthread -Wall -I src -lbauer
int main(int argc, char const *argv[])
{
  bauer_task_pool_thread tasker(exec);
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
  bauer_tcp_svr server(tasker, server_node);
  server.start();

  return 0;
}