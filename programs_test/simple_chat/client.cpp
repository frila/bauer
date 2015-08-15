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

  std::string a;
  bauer_tcp_data_string data;
  while(true){
    std::cin >> a;
    data = a;
    client.send(data);
    client.recv(data);
    std::cout << std::string("[Server] - ") << data.get() << std::endl;
  }

  return 0;
}