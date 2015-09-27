#include <iostream>
#include "bauer.h"

using namespace bauer;

//g++ -std=c++11  -o bin/client programs_test/simple_chat/client.cpp -Iinc -pthread -Wall -I src -Lbin -lbauer
int main(int argc, char const *argv[])
{
  bauer_node server_node(tcp_socket(), "10.10.10.10", 9999);
  bauer_tcp_clnt client;
  int a;
  std::cout << "Client - Tentando conectar" << std::endl;
  client.connect(server_node);
  std::cout << "Client - Connectado no Server" << std::endl;
  //bauer_tcp_data_file data(argv[1]);
  std::cin >> a;
  bauer_tcp_data_bool data;
  
  std::cout << client.recv(data) << std::endl;
  std::cout << (data.get() ? "Verdade" : "Falso") << std::endl;
  
  return 0;
}