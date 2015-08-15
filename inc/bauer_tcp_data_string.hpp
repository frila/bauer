#ifndef BAUER_TCP_DATA_STRING_HPP
#define BAUER_TCP_DATA_STRING_HPP

#include <iostream>
#include "bauer_tcp_data.hpp"

namespace bauer {

class bauer_tcp_data_string : public bauer_tcp_data
{

private:
  std::string data;
protected:
  size_t send(bauer_node remote);
  size_t recv(bauer_node remote);

public:
  bauer_tcp_data_string();
  bauer_tcp_data_string(char* _data);
  bauer_tcp_data_string(std::string _data);
  ~bauer_tcp_data_string();
  std::string& get();

  bauer_tcp_data_string& operator=(const bauer_tcp_data_string &d);
  bauer_tcp_data_string& operator=(const std::string &d);
  bauer_tcp_data_string& operator=(const char d[]);
  
  operator std::string() const
  {
    return data;
  }
};

} // bauer

#endif