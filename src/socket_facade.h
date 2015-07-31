#ifndef SOCKET_FACADE_H
#define SOCKET_FACADE_H

namespace sckt {
#ifdef _WIN32

#elif _WIN64

#else // Unix

#include <sys/socket.h>//socket
#include <arpa/inet.h> //inet_addr
#include <sys/types.h> /* for predefined symbolic constants and data structures */

/* Address families.  */
const int _AF_UNSPEC = AF_UNSPEC;
const int _AF_LOCAL = AF_LOCAL;
const int _AF_UNIX = AF_UNIX;
const int _AF_FILE = AF_FILE;
const int _AF_INET = AF_INET;
const int _AF_AX25 = AF_AX25;
const int _AF_IPX = AF_IPX;
const int _AF_APPLETALK = AF_APPLETALK;
const int _AF_NETROM = AF_NETROM;
const int _AF_BRIDGE = AF_BRIDGE;
const int _AF_ATMPVC = AF_ATMPVC;
const int _AF_X25 = AF_X25;
const int _AF_INET6 = AF_INET6;
const int _AF_ROSE = AF_ROSE;
const int _AF_DECnet = AF_DECnet;
const int _AF_NETBEUI = AF_NETBEUI;
const int _AF_SECURITY = AF_SECURITY;
const int _AF_KEY = AF_KEY;
const int _AF_NETLINK = AF_NETLINK;
const int _AF_ROUTE = AF_ROUTE;
const int _AF_PACKET = AF_PACKET;
const int _AF_ASH = AF_ASH;
const int _AF_ECONET = AF_ECONET;
const int _AF_ATMSVC = AF_ATMSVC;
const int _AF_RDS = AF_RDS;
const int _AF_SNA = AF_SNA;
const int _AF_IRDA = AF_IRDA;
const int _AF_PPPOX = AF_PPPOX;
const int _AF_WANPIPE = AF_WANPIPE;
const int _AF_LLC = AF_LLC;
const int _AF_CAN = AF_CAN;
const int _AF_TIPC = AF_TIPC;
const int _AF_BLUETOOTH = AF_BLUETOOTH;
const int _AF_IUCV = AF_IUCV;
const int _AF_RXRPC = AF_RXRPC;
const int _AF_ISDN = AF_ISDN;
const int _AF_PHONET = AF_PHONET;
const int _AF_IEEE802154 = AF_IEEE802154;
const int _AF_CAIF = AF_CAIF;
const int _AF_ALG = AF_ALG;
const int _AF_NFC = AF_NFC;
const int _AF_VSOCK = AF_VSOCK;
const int _AF_MAX = AF_MAX;

/* Types of sockets.  */
const int _SOCK_STREAM = SOCK_STREAM;
const int _SOCK_DGRAM = SOCK_DGRAM;
const int _SOCK_RAW = SOCK_RAW;
const int _SOCK_RDM = SOCK_RDM;
const int _SOCK_SEQPACKET = SOCK_SEQPACKET;
const int _SOCK_DCCP = SOCK_DCCP;
const int _SOCK_PACKET = SOCK_PACKET;
const int _SOCK_CLOEXEC = SOCK_CLOEXEC;
const int _SOCK_NONBLOCK = SOCK_NONBLOCK;

const int _IPPROTO_IP = IPPROTO_IP;
const int _IPPROTO_ICMP = IPPROTO_ICMP;
const int _IPPROTO_IGMP = IPPROTO_IGMP;
const int _IPPROTO_IPIP = IPPROTO_IPIP;
const int _IPPROTO_TCP = IPPROTO_TCP;
const int _IPPROTO_EGP = IPPROTO_EGP;
const int _IPPROTO_PUP = IPPROTO_PUP;
const int _IPPROTO_UDP = IPPROTO_UDP;
const int _IPPROTO_IDP = IPPROTO_IDP;
const int _IPPROTO_TP = IPPROTO_TP;
const int _IPPROTO_DCCP = IPPROTO_DCCP;
const int _IPPROTO_IPV6 = IPPROTO_IPV6;
const int _IPPROTO_RSVP = IPPROTO_RSVP;
const int _IPPROTO_GRE = IPPROTO_GRE;
const int _IPPROTO_ESP = IPPROTO_ESP;
const int _IPPROTO_AH = IPPROTO_AH;
const int _IPPROTO_MTP = IPPROTO_MTP;
const int _IPPROTO_BEETPH = IPPROTO_BEETPH;
const int _IPPROTO_ENCAP = IPPROTO_ENCAP;
const int _IPPROTO_PIM = IPPROTO_PIM;
const int _IPPROTO_COMP = IPPROTO_COMP;
const int _IPPROTO_SCTP = IPPROTO_SCTP;
const int _IPPROTO_UDPLITE = IPPROTO_UDPLITE;
const int _IPPROTO_RAW = IPPROTO_RAW;
const int _IPPROTO_MAX = IPPROTO_MAX;

/* Address to accept any incoming messages.  */
const int _INADDR_ANY = INADDR_ANY;
/* Address to send to all hosts.  */
const int _INADDR_BROADCAST = INADDR_BROADCAST;
/* Address indicating an error return.  */
const int _INADDR_NONE = INADDR_NONE;

#endif
}


#endif // SOCKET_FACADE_H
