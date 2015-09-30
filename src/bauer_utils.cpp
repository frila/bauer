#include "bauer_utils.hpp"
#include <cstring>

namespace bauer
{

std::string bauer_node2string(bauer_node node)
{
	int n = 21;// mascara 000.000.000.000:0000
    char *d = new char[n];
    std::memset(d,0,sizeof(char)*n);
    std::sprintf(d, "%s:%d", node.get_ip().data(), node.get_port());
    return std::string(d);
}

bauer_node string2bauer_node(std::string str)
{
	int ip_mask_length = 15;// 000.000.000.000
    char *str_ip = new char[ip_mask_length];
    short port;
    std::sscanf(str.data(),"%s:%d",str_ip,&port);
    return bauer_node(std::string(str_ip), port);
}

}