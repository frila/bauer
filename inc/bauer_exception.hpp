#ifndef BAUER_EXCEPTION
#define BAUER_EXCEPTION

#include <iostream>
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

    bauer_exception();
    virtual ~bauer_exception() _GLIBCXX_USE_NOEXCEPT;
    bauer_exception(char *_message, bauer_exception *_inner);
    bauer_exception(std::string _message);
    bauer_exception inner_exception();
    virtual const char* what() const throw();
  };

  class bauer_socket_exception : public bauer_exception
  {
  protected:
    int code;
  public:
    bauer_socket_exception();
  };

}

#endif