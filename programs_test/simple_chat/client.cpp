#include <iostream>
#include "bauer_tcp.hpp"
#include "bauer_tcp_clnt.hpp"
#include "bauer_node.hpp"

using namespace bauer;

//g++ -o bin/client programs_test/simple_chat/client.cpp -pthread -Wall
int main(int argc, char const *argv[])
{
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9997);
  bauer_tcp_clnt client;

  client.connect(server_node);
  std::cout << "Client - Connectado no Server" << std::endl;

  std::string a;
  while(true){
    std::cin >> a; 
    client.send(a);
    client.recv(a);
    std::cout << std::string("[Server] - ") << a << std::endl;
  }

  return 0;
}