LDFLAGS=-std=c++11  -g

all: ; g++ $(LDFLAGS) testGame.cpp Archer.cpp Board.cpp Fighter.cpp Game.cpp InputParser.cpp Player.cpp Priest.cpp Scout.cpp Tank.cpp -o hw4;
run: ; ./hw4 

valgrind: ; valgrind --leak-check=full ./hw4
clean: ; rm -rf hw4;
