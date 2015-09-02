[![Build Status](http://104.236.110.35:8081/api/badge/github.com/frila/bauer/status.svg?branch=master)](http://104.236.110.35:8081/github.com/frila/bauer)

#Bauer


##Documentação
Para utilizar o bauer deve-se incluir o arquivo 

```c
#include "bauer.hpp"
```

####BauerNode
Tipo de dado utilizado para referenciar um nó na rede.

**Construtor**:

#####Cabeçalho
```c
bauer_node();
bauer_node(bsocket_t _socket, bauer_ip _ip, bauer_port _port)
bauer_node(bauer_ip _ip, bauer_port _port)
```
Construtor simples para um BauerNode

#####Parametro
 > **bsocket_t socket**: instancia de socket
 > **bauer_ip ip**: Ip do nó de destino
 > **bauer_port port**: Porta do nó de destino


#####Exemplo
```c
bauer_node node;
bauer_node *node = new bauer_node();

bauer_node node(tcp_socket(), "1.1.1.1.",9090);
bauer_node *node = new bauer_node(tcp_socket(), "1.1.1.1.",9090);

bauer_node node("1.1.1.1.",9090);
bauer_node *node = new bauer_node("1.1.1.1.",9090);

```