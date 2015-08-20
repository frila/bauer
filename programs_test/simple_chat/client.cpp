#include <iostream>
#include "bauer.h"

using namespace bauer;

//g++ -std=c++11  -o bin/client programs_test/simple_chat/client.cpp -Iinc -pthread -Wall -I src -Lbin -lbauer
int main(int argc, char const *argv[])
{
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
  bauer_tcp_clnt client;

  client.connect(server_node);
  std::cout << "Client - Connectado no Server" << std::endl;
  bauer_tcp_data_file data("teste.jpg");
  client.recv(data);
  
  return 0;
}