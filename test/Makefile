CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
DEP=../src
BIN=bin

INC=-I/opt/gtest/include -I../src -Isrc -I$(DEPINC) -L$(DEPLIB)

DEPINC=/usr/local/include
DEPLIB=/usr/local/lib

FLAGS=-g -L/opt/gtest/lib -lgtest -lgtest_main -pthread
OBJS=$(OBJ)/bauer_node_test.o $(OBJ)/bauer_tcp_test.o

NAME=test-all

test-all: $(OBJS)
	$(CC) -o $(BIN)/$(NAME) $(OBJS) $(INC) $(FLAGS)

#### building test source
$(OBJ)/test_main.o:
	$(CC) -o $(OBJ)/test_main.o -c $(SRC)/test_main.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_node_test.o: $(SRC)/bauer_node_test.cpp
	$(CC) -o $(OBJ)/bauer_node_test.o -c $(SRC)/bauer_node_test.cpp $(INC) $(FLAGS)

$(OBJ)/bauer_tcp_test.o: $(SRC)/bauer_tcp_test.cpp
	$(CC) -o $(OBJ)/bauer_tcp_test.o -c $(SRC)/bauer_tcp_test.cpp $(INC) $(FLAGS)

# #### building dependencies
# $(OBJ)/bauer_node.o: $(DEP)/bauer_node.cpp
# 	$(CC) -o $(OBJ)/bauer_node.o -c $(DEP)/bauer_node.cpp $(INC) $(FLAGS)

clean:
	rm -rf $(OBJ) $(BIN)/$(NAME)
	mkdir $(OBJ) 