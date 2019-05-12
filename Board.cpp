#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Board::Board(unsigned int _size, std::vector<Player*>* _players, Coordinate chest):
	size(_size),
	players(_players),
	chest(chest)
{

}

Board::~Board(){
}

bool Board::isCoordinateInBoard(const Coordinate& c){
	if(0<=c.x && 0<=c.y && c.x<size && c.y<size){
		return true;
	}
	return false;
}

bool Board::isPlayerOnCoordinate(const Coordinate& c){
	for(int i=0; i<players->size(); i++){
		if((players->at(i))->getCoord() == c){
			return true;
		}
	}
	return false;
}

Player * Board::operator [](const Coordinate& c){
	for(int i=0; i<players->size(); i++){
		if((players->at(i))->getCoord() == c){
			return players->at(i);
		}
	}
	return NULL;
}

Coordinate Board::getChestCoordinates(){
	return chest;
}

void Board::printBoardwithID(){
	Coordinate current = Coordinate(0,0);
	for(int i=0; i<this->size; i++){
		for(int j=0; j<this->size; j++){
			current = {j,i};
			if(isPlayerOnCoordinate(current)){
				std::cout << (*this)[current]->getBoardID() << " ";
			}
			else if(current==this->chest){
				std::cout << "Ch ";
			}
			else{
				std::cout << "__ ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::printBoardwithClass(){
	Coordinate current = Coordinate(0,0);
	for(int i=0; i<this->size; i++){
		for(int j=0; j<this->size; j++){
			current = {j,i};
			if(isPlayerOnCoordinate(current)){
				std::cout << ((*this)[current])->getClassAbbreviation() << " ";
			}
			else if(current==this->chest){
				std::cout << "Ch ";
			}
			else{
				std::cout << "__ ";
			}
		}
		std::cout << std::endl;
	}
}
