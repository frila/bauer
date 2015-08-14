NAME=bauer
CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
LIBPATH=/usr/local/lib

DEPINC=/usr/local/include
DEPLIB=/usr/local/lib

FLAGS=-std=c++11 -g -fPIC

INC=-I/opt/gtest/include -Iinc -Isrc -I$(DEPINC) -L$(DEPLIB)

OBJS=$(OBJ)/bauer_node.o $(OBJ)/bauer_exception.o $(OBJ)/bauer_task_pool_thread.o $(OBJ)/bauer_task_process.o $(OBJ)/bauer_task_serial.o $(OBJ)/bauer_task_thread.o $(OBJ)/bauer_tcp_conn.o $(OBJ)/bauer_tcp.o $(OBJ)/bauer_tcp_clnt.o $(OBJ)/bauer_tcp_svr.o $(OBJ)/bauer_file.o

all: dependency $(OBJS)
	$(CC) -o $(BIN)/lib$(NAME).so $(OBJS) $(FLAGS) -shared -pthread

dependency:
	mkdir -p obj
	mkdir -p bin

install: all
	cp $(BIN)/lib$(NAME).so $(LIBPATH)
	ldconfig

clean:
	rm -rf $(OBJ) $(BIN)/*
	mkdir $(OBJ) 

###### building dependencies
$(OBJ)/bauer_node.o: $(SRC)/bauer_node.cpp
	$(CC) -o $(OBJ)/bauer_node.o -c $(SRC)/bauer_node.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_exception.o: $(SRC)/bauer_exception.cpp
	$(CC) -o $(OBJ)/bauer_exception.o -c $(SRC)/bauer_exception.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_task_pool_thread.o: $(SRC)/bauer_task_pool_thread.cpp
	$(CC) -o $(OBJ)/bauer_task_pool_thread.o -c $(SRC)/bauer_task_pool_thread.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_task_process.o: $(SRC)/bauer_task_process.cpp
	$(CC) -o $(OBJ)/bauer_task_process.o -c $(SRC)/bauer_task_process.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_task_serial.o: $(SRC)/bauer_task_serial.cpp
	$(CC) -o $(OBJ)/bauer_task_serial.o -c $(SRC)/bauer_task_serial.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_task_thread.o: $(SRC)/bauer_task_thread.cpp
	$(CC) -o $(OBJ)/bauer_task_thread.o -c $(SRC)/bauer_task_thread.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_conn.o: $(SRC)/bauer_tcp_conn.cpp
	$(CC) -o $(OBJ)/bauer_tcp_conn.o -c $(SRC)/bauer_tcp_conn.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp.o: $(SRC)/bauer_tcp.cpp
	$(CC) -o $(OBJ)/bauer_tcp.o -c $(SRC)/bauer_tcp.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_clnt.o: $(SRC)/bauer_tcp_clnt.cpp
	$(CC) -o $(OBJ)/bauer_tcp_clnt.o -c $(SRC)/bauer_tcp_clnt.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_svr.o: $(SRC)/bauer_tcp_svr.cpp
	$(CC) -o $(OBJ)/bauer_tcp_svr.o -c $(SRC)/bauer_tcp_svr.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_task_mngr.o: $(SRC)/bauer_task_mngr.cpp
	$(CC) -o $(OBJ)/bauer_task_mngr.o -c $(SRC)/bauer_task_mngr.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_file.o: $(SRC)/bauer_file.cpp
	$(CC) -o $(OBJ)/bauer_file.o -c $(SRC)/bauer_file.cpp $(INC) $(FLAGS)
