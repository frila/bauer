all:
	g++ -std=c++11 -o bin/bauer src/main.cpp -pthread -Wall

test:
	g++ -std=c++11 -o test/bin/bauer_tests test/src/main.cpp -g -L/opt/gtest/lib -lgtest -lgtest_main -I./ -Isrc -Itest/src -I/opt/gtest/include -Wall