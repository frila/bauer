#include "bauer_node.hpp"
#include "bauer_tcp.hpp"

int main(int argc, char const *argv[])
{
  std::cout << bauer::tcp_socket() << std::endl;
  std::cout << "hello, bauer" << std::endl;
  return 0;
}