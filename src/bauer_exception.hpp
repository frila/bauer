#ifndef BAUER_EXCEPTION
#define BAUER_EXCEPTION

#include <exception>
#include <errno.h>
#include <string.h>

namespace bauer
{
  class bauer_exception : public std::exception
  {
  protected:
    bauer_exception *inner;
    std::string message;
  public:

    bauer_exception() : exception() {}

    bauer_exception(char *_message, bauer_exception *_inner) : exception() 
    {
      message = _message;
      inner = _inner;
    }

    bauer_exception(std::string _message) : exception() 
    {
      message = _message;
      inner = NULL;
    }

    bauer_exception inner_exception()
    {
      return *inner;
    }

    virtual const char* what() const throw()
    {
      return message.c_str();
    }
  };

  class bauer_socket_exception : public bauer_exception
  {
  protected:
    int code;
  public:
    bauer_socket_exception() : bauer_exception()
    {
      code = errno;
      message = std::string(strerror(errno));
    }
    
  };

}

#endif