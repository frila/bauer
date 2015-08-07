all:
	g++ -std=c++11 -o bin/bauer src/main.cpp -pthread -Wall

clean:
	rm -rf bin/
	mkdir bin