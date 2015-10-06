#include "bauer_tcp_data_file.hpp"

namespace bauer {

bauer_tcp_data_file::bauer_tcp_data_file(std::string _path, bauer_file_mode _mode)
  : bauer_tcp_data(), path(_path), mode(_mode)
{
  bfs = new char[size_buffer];
  recv_iter_function = NULL;
  send_iter_function = NULL;
}

bauer_tcp_data_file::~bauer_tcp_data_file()
{
}

void bauer_tcp_data_file::open_file_input()
{
  fs.open (path.c_str(), std::fstream::in | std::fstream::binary | std::fstream::ate);
}

void bauer_tcp_data_file::send_size(bauer_node remote, size_t size)
{
  bauer_tcp_data_int size_data = (int)size;
  size_data.send(remote);
}

size_t bauer_tcp_data_file::send(bauer_node remote)
{
  size_t initial_byte = recv_start_chunck(remote);
  open_file_input();
  size_t r = 0;
  if(fs.is_open())
  {
    size = fs.tellg();
    send_size(remote,size);

    if (initial_byte != size)
    {
      fs.seekg(initial_byte);
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

        if(send_iter_function) {
          send_iter_function(r,size);
        }

      }
      while(size);
      r += bauer_tcp_data::send(bfs, remote,0);
      if(send_iter_function) {
        send_iter_function(r,size);
      }
    }
  } 
  else 
  {
    throw bauer_exception("Open file Error");
  }
  fs.close();
}

size_t bauer_tcp_data_file::recv_size(bauer_node remote)
{
  bauer_tcp_data_int size_data;
  size_data.recv(remote);
  return size_data.get();
}

size_t bauer_tcp_data_file::get_size_file()
{
  int size = 0;
  std::fstream fsi;
  fsi.open (path.c_str(), std::fstream::app | std::fstream::binary);
  size = fsi.tellg();
  fsi.close();
  return size;
}

size_t bauer_tcp_data_file::send_start_chunck(bauer_node remote)
{
  bauer_tcp_data_int size;
  if (mode == bauer_file_mode::CHUCK_CONTINUOS)
  {
    size = (int) get_size_file();
  }
  else if (mode == bauer_file_mode::CHUCK_RESTART)
  {
    size = 0;
  }
  size.send(remote);
  return size.get();
}

size_t bauer_tcp_data_file::recv_start_chunck(bauer_node remote)
{
  bauer_tcp_data_int size;
  size.recv(remote);
  return size.get();
}

size_t bauer_tcp_data_file::recv(bauer_node remote)
{
  size_t initial_size = send_start_chunck(remote);
  size_t r = initial_size,
    s = 0,
    size = recv_size(remote);

  if ( initial_size < size)
  {
    if (initial_size > 0 )
    {
      fs.open(path.c_str(), std::ofstream::out | std::fstream::app | std::fstream::binary);
    }
    else
    {
      fs.open (path.c_str(), std::fstream::out | std::fstream::binary);
    }
    if (fs.is_open())
    {
      int t_size = fs.tellg();
      fs.seekg(0, std::fstream::beg);
      do
      {
        std::memset(bfs, 0, sizeof(char) * size_buffer);
        s = bauer_tcp_data::recv(bfs, remote);
        fs.write(bfs, s);

        r += s;

        if (recv_iter_function) {
          recv_iter_function(r,size);
        }
      }
      while(r < size);
      fs.close();
    }
    else
    {
      throw bauer_exception("Open file Error");
    }
  }
}

void bauer_tcp_data_file::set_recv_iter_function(void (*_recv_iter_function)(size_t,size_t)) {
  recv_iter_function = _recv_iter_function;
}

void bauer_tcp_data_file::set_send_iter_function(void (*_send_iter_function)(size_t,size_t)) {
  send_iter_function = _send_iter_function;
}



} // bauer
