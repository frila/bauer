NAME=bauer
CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
INC=inc
LIBPATH=/usr/local/lib

DEPINC=/usr/local/include
DEPLIB=/usr/local/lib

FLAGS=-std=c++11 -g -fPIC

INCCMD=-I/opt/gtest/include -I$(INC) -I$(SRC) -I$(DEPINC) -L$(DEPLIB)

OBJS=$(OBJ)/bauer_node.o $(OBJ)/bauer_exception.o $(OBJ)/bauer_task_pool_thread.o $(OBJ)/bauer_task_process.o $(OBJ)/bauer_task_serial.o $(OBJ)/bauer_task_thread.o $(OBJ)/bauer_tcp.o $(OBJ)/bauer_tcp_clnt.o $(OBJ)/bauer_tcp_svr.o $(OBJ)/bauer_task_mngr.o $(OBJ)/bauer_tcp_channel.o $(OBJ)/bauer_tcp_data.o $(OBJ)/bauer_tcp_data_string.o $(OBJ)/bauer_tcp_data_file.o $(OBJ)/bauer_tcp_data_int.o $(OBJ)/bauer_tcp_data_bool.o $(OBJ)/bauer_utils.o 

all: dependency $(OBJS)
	$(CC) -o $(BIN)/lib$(NAME).so $(OBJS) $(FLAGS) -shared -pthread

dependency:
	mkdir -p obj
	mkdir -p bin

install: all
	cp $(BIN)/lib$(NAME).so $(LIBPATH)
	mkdir -p $(DEPINC)/bauer
	cp $(INC)/* $(DEPINC)/bauer
	cp $(INC)/bauer.h $(DEPINC)
	ldconfig

clean:
	rm -rf $(OBJ) $(BIN)/*
	mkdir $(OBJ) 

###### building dependencies
$(OBJ)/bauer_node.o: $(SRC)/bauer_node.cpp
	$(CC) -o $(OBJ)/bauer_node.o -c $(SRC)/bauer_node.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_exception.o: $(SRC)/bauer_exception.cpp
	$(CC) -o $(OBJ)/bauer_exception.o -c $(SRC)/bauer_exception.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_task_pool_thread.o: $(SRC)/bauer_task_pool_thread.cpp
	$(CC) -o $(OBJ)/bauer_task_pool_thread.o -c $(SRC)/bauer_task_pool_thread.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_task_process.o: $(SRC)/bauer_task_process.cpp
	$(CC) -o $(OBJ)/bauer_task_process.o -c $(SRC)/bauer_task_process.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_task_serial.o: $(SRC)/bauer_task_serial.cpp
	$(CC) -o $(OBJ)/bauer_task_serial.o -c $(SRC)/bauer_task_serial.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_task_thread.o: $(SRC)/bauer_task_thread.cpp
	$(CC) -o $(OBJ)/bauer_task_thread.o -c $(SRC)/bauer_task_thread.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_conn.o: $(SRC)/bauer_tcp_conn.cpp
	$(CC) -o $(OBJ)/bauer_tcp_conn.o -c $(SRC)/bauer_tcp_conn.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp.o: $(SRC)/bauer_tcp.cpp
	$(CC) -o $(OBJ)/bauer_tcp.o -c $(SRC)/bauer_tcp.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_clnt.o: $(SRC)/bauer_tcp_clnt.cpp
	$(CC) -o $(OBJ)/bauer_tcp_clnt.o -c $(SRC)/bauer_tcp_clnt.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_svr.o: $(SRC)/bauer_tcp_svr.cpp
	$(CC) -o $(OBJ)/bauer_tcp_svr.o -c $(SRC)/bauer_tcp_svr.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_task_mngr.o: $(SRC)/bauer_task_mngr.cpp
	$(CC) -o $(OBJ)/bauer_task_mngr.o -c $(SRC)/bauer_task_mngr.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_file.o: $(SRC)/bauer_file.cpp
	$(CC) -o $(OBJ)/bauer_file.o -c $(SRC)/bauer_file.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_channel.o: $(SRC)/bauer_tcp_channel.cpp
	$(CC) -o $(OBJ)/bauer_tcp_channel.o -c $(SRC)/bauer_tcp_channel.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_data.o: $(SRC)/bauer_tcp_data.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data.o -c $(SRC)/bauer_tcp_data.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_data_string.o: $(SRC)/bauer_tcp_data_string.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data_string.o -c $(SRC)/bauer_tcp_data_string.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_data_file.o: $(SRC)/bauer_tcp_data_file.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data_file.o -c $(SRC)/bauer_tcp_data_file.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_data_int.o: $(SRC)/bauer_tcp_data_int.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data_int.o -c $(SRC)/bauer_tcp_data_int.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_tcp_data_bool.o: $(SRC)/bauer_tcp_data_bool.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data_bool.o -c $(SRC)/bauer_tcp_data_bool.cpp $(INCCMD) $(FLAGS)

$(OBJ)/bauer_utils.o: $(SRC)/bauer_utils.cpp
	$(CC) -o $(OBJ)/bauer_utils.o -c $(SRC)/bauer_utils.cpp $(INCCMD) $(FLAGS)
