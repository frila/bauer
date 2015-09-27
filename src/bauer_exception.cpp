  #include "bauer_exception.hpp"

namespace bauer
{

  bauer_exception::bauer_exception() : exception() {

  }

  bauer_exception::bauer_exception(char *_message, bauer_exception *_inner) : exception() 
  {
    message = _message;
    inner = _inner;
  }

  bauer_exception::bauer_exception(std::string _message) : exception() 
  {
    message = _message;
    inner = NULL;
  }

  bauer_exception::~bauer_exception() _GLIBCXX_USE_NOEXCEPT {}  // nao me pergunte pq essa porra na frente do destrutor

  bauer_exception bauer_exception::inner_exception()
  {
    return *inner;
  }

  const char* bauer_exception::what() const throw()
  {
    return message.c_str();
  }

  bauer_socket_exception::bauer_socket_exception() : bauer_exception()
  {
    code = errno;
    message = std::string(strerror(errno));
  }

  bauer_socket_connect_timeout_exception::bauer_socket_connect_timeout_exception() : bauer_socket_exception(){ }

  bauer_file_exception::bauer_file_exception() : bauer_exception()
  {
    code = errno;
    message = std::string(strerror(errno));
  }

  bauer_file_exception::bauer_file_exception(std::string _message) : bauer_exception()
  {
    code = errno;
    message = _message;
  }
}
