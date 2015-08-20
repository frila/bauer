#include "bauer_tcp_data_file.hpp"

namespace bauer {

bauer_tcp_data_file::bauer_tcp_data_file(std::string _path)
  : bauer_tcp_data(), path(_path)
{
  bfs = new char[size_buffer];
}

bauer_tcp_data_file::~bauer_tcp_data_file()
{
}

//http://www.cplusplus.com/doc/tutorial/files/
size_t bauer_tcp_data_file::send(bauer_node remote)
{
  fs.open (path.c_str(), std::fstream::in | std::fstream::binary | std::fstream::ate);
  size_t r = 0;
  if(fs.is_open())
  {
    size = fs.tellg();
    bauer_tcp_data_int size_data = (int)size;
    size_data.send(remote);
    std::cout << size << std::endl;
    fs.seekg(0, std::fstream::beg);
    do
    {
      size_t request_size = 0;
      if (size > size_buffer)
      {
        request_size = size_buffer;
        size -= size_buffer;
      }
      else
      {
        request_size = size;
        size = 0;
      }
      std::memset(bfs, 0, sizeof(char) * request_size);
      fs.read(bfs, request_size);
      r += bauer_tcp_data::send(bfs, remote,request_size);
    }
    while(size);
    std::cout << "terminou " << std::endl;
    r += bauer_tcp_data::send(bfs, remote,0);
  } 
  else 
  {
    throw bauer_exception("Open file Error");
  }
  fs.close();
}

size_t bauer_tcp_data_file::recv(bauer_node remote)
{
  size_t r = 0;
  fs.open (path.c_str(), std::fstream::out | std::fstream::binary);
  if (fs.is_open())
  {
    bauer_tcp_data_int size_data;
    size_t s = 0, size;
    size_data.recv(remote);
    size = size_data.get();
    std::cout << size << std::endl;
    do
    {
      std::memset(bfs, 0, sizeof(char) * size_buffer);
      s = bauer_tcp_data::recv(bfs, remote);
      fs.write(bfs, s);
      r += s;
      std::cout << r << std::endl;
    }
    while(r < size);
    std::cout << "terminou " << std::endl;
    fs.close();
  }
  else
  {
    throw bauer_exception("Open file Error");
  }
}


} // bauer