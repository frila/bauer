#include <fcntl.h>
#include <sys/time.h>
#include "bauer_tcp_clnt.hpp"

namespace bauer {

  bauer_tcp_clnt::bauer_tcp_clnt() {}
  bauer_tcp_clnt::~bauer_tcp_clnt() {}

  void bauer_tcp_clnt::connect(bauer_node &node, int timeout_seconds) throw(bauer_socket_exception){
    int res; 
    long arg; 
    fd_set myset; 
    struct timeval tv; 
    int valopt; 
    sckt::socklen_t lon;
    bsocket_t sock = tcp_socket();

    sckt::sockaddr_in server;

    channel.set_target(node);
    server.sin_addr.s_addr = sckt::inet_addr(channel.get_target().get_ip().c_str());
    server.sin_family = sckt::_AF_INET;
    server.sin_port = sckt::htons(channel.get_target().get_port());

    // Set non-blocking 
    if( (arg = fcntl(sock, F_GETFL, NULL)) < 0) { 
       throw bauer_socket_exception();
    } 
    arg |= O_NONBLOCK; 
    if( fcntl(sock, F_SETFL, arg) < 0) { 
       throw bauer_socket_exception();
    }

    res = sckt::connect(sock , (sckt::sockaddr *)&server , (sckt::socklen_t) sizeof(server));
    
      if (res < 0) { 
         if (errno == EINPROGRESS) { 
            do { 
               tv.tv_sec = timeout_seconds; 
               tv.tv_usec = 0; 
               FD_ZERO(&myset); 
               FD_SET(sock, &myset); 
               res = select(sock+1, NULL, &myset, NULL, &tv); 
               if (res < 0 && errno != EINTR) { 
                  throw bauer_socket_exception();
               } 
               else if (res > 0) { 
                  // Socket selected for write 
                  lon = sizeof(int); 
                  if (sckt::getsockopt(sock, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon) < 0) { 
                     throw bauer_socket_exception();
                  } 
                  // Check the value returned... 
                  if (valopt) { 
                     throw bauer_socket_exception();
                  } 
                  break; 
               } 
               else {
                  throw bauer_socket_connect_timeout_exception();
               } 
            } while (1);
         } 
         else { 
            throw bauer_socket_exception();
         } 
      }
    // Set to blocking mode again... 
    if( (arg = fcntl(sock, F_GETFL, NULL)) < 0) { 
       throw bauer_socket_exception();
    } 
    arg &= (~O_NONBLOCK); 
    if( fcntl(sock, F_SETFL, arg) < 0) { 
       throw bauer_socket_exception();
    }
    
    channel.get_target().set_socket(sock);

  }

  size_t bauer_tcp_clnt::send(bauer_tcp_data &data)
  {

    return channel.send(data);
  }

  size_t bauer_tcp_clnt::recv(bauer_tcp_data &data)
  {
    return channel.recv(data);
  }

}
