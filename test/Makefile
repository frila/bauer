CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
DEP=../src
BIN=bin

DEPINC=/usr/local/include
DEPLIB=/usr/local/lib
BAUERLIB=../bin

INC=-I/opt/gtest/include -I../inc -Isrc -I$(DEPINC) -L$(DEPLIB) -L$(BAUERLIB)

FLAGS=-std=c++11 -g -L/opt/gtest/lib -lgtest -lgtest_main -pthread -lbauer
OBJS=$(OBJ)/bauer_node_test.o $(OBJ)/bauer_tcp_test.o $(OBJ)/bauer_file_test.o $(OBJ)/bauer_tcp_data_string_test.o

NAME=test-all

test-all: dep $(OBJS)
	$(CC) -o $(BIN)/$(NAME) $(OBJS) $(INC) $(FLAGS)

dep:
	mkdir -p obj
	mkdir -p bin

#### building test source
$(OBJ)/test_main.o:
	$(CC) -o $(OBJ)/test_main.o -c $(SRC)/test_main.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_node_test.o: $(SRC)/bauer_node_test.cpp
	$(CC) -o $(OBJ)/bauer_node_test.o -c $(SRC)/bauer_node_test.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_test.o: $(SRC)/bauer_tcp_test.cpp
	$(CC) -o $(OBJ)/bauer_tcp_test.o -c $(SRC)/bauer_tcp_test.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_file_test.o: $(SRC)/bauer_file_test.cpp
	$(CC) -o $(OBJ)/bauer_file_test.o -c $(SRC)/bauer_file_test.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_data_string_test.o: $(SRC)/bauer_tcp_data_string_test.cpp
	$(CC) -o $(OBJ)/bauer_tcp_data_string_test.o -c $(SRC)/bauer_tcp_data_string_test.cpp $(INC) $(FLAGS)

clean:
	rm -rf $(OBJ) $(BIN)/$(NAME)
