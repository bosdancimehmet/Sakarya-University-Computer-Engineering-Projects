all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/fs.cpp -o ./lib/fs.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++   ./lib/fs.o ./lib/main.o -o ./bin/program

calistir:
	./bin/program