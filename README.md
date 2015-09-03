[![Build Status](http://104.236.110.35:8081/api/badge/github.com/frila/bauer/status.svg?branch=master)](http://104.236.110.35:8081/github.com/frila/bauer)

#Bauer

-------------------------------------------------------------
##Documentação
Para utilizar o bauer deve-se incluir o arquivo 

```c
#include "bauer.h"
```
-------------------------------------------------------------
####bauer_node
Tipo de dado utilizado para referenciar um nó na rede.

**Construtor**:

```c
bauer_node();
bauer_node(bsocket_t _socket, bauer_ip _ip, bauer_port _port)
bauer_node(bauer_ip _ip, bauer_port _port)
```

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
**Getter & Setter**
```c
bsocket_t get_socket();
bauer_ip get_ip();
bauer_port get_port();
void set_socket(bsocket_t val);
void set_ip(bauer_ip val);
void set_port(bauer_port val);
```
-------------------------------------------------------------
####bauer_tcp_clnt
Tipo de dado utilizado para manipular um cliente.

**Construtor**:

```c
bauer_tcp_clnt();
```
 
#####Exemplo
```c
bauer_tcp_clnt client;
bauer_tcp_clnt *client = new bauer_tcp_clnt();

```

**Operações**

```c
void connect(bauer_node &node) throw(bauer_socket_exception);
```
Conecta a um servidor, instanciado no endereço em um nó

```c
size_t send(bauer_tcp_data &data);
```
Envia um dado para o servidor conetado
```c
size_t recv(bauer_tcp_data &data);
```
Recebe um dado do servidor conectado
#####Exemplo
```c
bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
bauer_tcp_clnt client;
client.connect(server_node);
bauer_tcp_data_string data = "Hello World";
client.send(data)
client.recv(data);
cout << data.get() << endl; // Imprime o dado recebido do servidor
```

-------------------------------------------------------------
####bauer_tcp_svr
Tipo de dado utilizado para manipular um servidor.

**Construtor**:

```c
bauer_tcp_svr(bauer_task_mngr &task_mng,bauer_node &_local);
```

#####Parametro
 > **bauer_task_mngr &task_mng**: Instacia um gerenciador de tarefas do servidor
 > **bauer_node &_local**: Define o ip,porta e socket aonde serão instaciado o servidor 
 
**Operações**
```c
void force();
```
Instancia o socket do servidor para TCP Socket
```c
void start();
```
Inicia o servidor para receber requisições

#####Exemplo
```c
bauer_task_pool_thread tasker(exec);
bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
bauer_tcp_svr server(tasker, server_node);
server.start();
```
-------------------------------------------------------------
####bauer_task
São gerenciadores de servidor.
Os Servidores pode ser:
> Servidor Serial - *bauer_task_serial*
> Servidor com Threads - *bauer_task_thread*
> Servidor com Processos - *bauer_task_process*
> Servidor com Pool de Threads - *bauer_task_pool_thread*

**Construtores**:

```c
bauer_task_serial( void (*_exec)(bauer_tcp_channel));
bauer_task_thread( void (*_exec)(bauer_tcp_channel));
bauer_task_process( void (*_exec)(bauer_tcp_channel));
bauer_task_pool_thread( void (*_exec)(bauer_tcp_channel));

```

#####Parametro
 > **void (*_exec)(bauer_tcp_channel)**: Função que executará quando o servidor parear uma conexão com o cliente
 

#####Exemplo
```c
void exec(bauer_tcp_channel remote){
  bauer_tcp_data_bool data = true;
  remote.send(data);
}

int main(int argc, char const *argv[])
{
  bauer_task_pool_thread tasker(exec);
  bauer_node server_node(tcp_socket(), "127.0.0.1", 9999);
  bauer_tcp_svr server(tasker, server_node);
  server.start();
  return 0;
}
```
-------------------------------------------------------------
####bauer_data
Os tipos de dados que podem ser enviados/recebidos
> Dados int - *bauer_tcp_data_int*
> Dados bool - *bauer_tcp_data_bool*
> Dados string - *bauer_tcp_data_string*
> Dados file - *bauer_tcp_data_file*


**Construtores**:

```c
bauer_tcp_data_string();
bauer_tcp_data_string(char* _data);
bauer_tcp_data_string(std::string _data);
```
```c
bauer_tcp_data_int();
bauer_tcp_data_int(int _data);
```
```c
bauer_tcp_data_file(std::string _path, bauer_file_mode _mode=bauer_file_mode::CHUCK_CONTINUOS);
```
#####Parametro
 > **std::string _path**: Caminho do arquivo
 > **bauer_file_mode _mode**: Modo o qual será aberto o arquivo
 > > bauer_file_mode::CHUCK_CONTINUOS (*default*)
 > > bauer_file_mode::CHUCK_RESTART

```c
bauer_tcp_data_bool();
bauer_tcp_data_bool(bool _data);
```
**Operações**
```c
TYPE get();
```
Retorna:
> TYPE=**int** : bauer_tcp_data_int
> TYPE=**bool** : bauer_tcp_data_bool
> TYPE=**string** : bauer_tcp_data_string
> TYPE=**ofstream** : bauer_tcp_data_file

#####Exemplo
```c
bauer_tcp_data_int a;
bauer_tcp_data_int a = 10;
bauer_tcp_data_int a(10);
int int_a = a
int int_b = a.get();

bauer_tcp_data_bool a;
bauer_tcp_data_bool a = false;
bauer_tcp_data_bool a(true);
bool bool_a = a;
bool bool_b = a.get();

bauer_tcp_data_string a;
bauer_tcp_data_string a("Hello World");
bauer_tcp_data_string a = "Hello World";
std::string string_a = a;
std::string string_b = a.get();

bauer_tcp_data_file a("path/to/file.txt",bauer_file_mode::CHUCK_CONTINUOS);
bauer_tcp_data_file a("path/to/file.txt",bauer_file_mode::CHUCK_RESTART);

```
-------------------------------------------------------------
