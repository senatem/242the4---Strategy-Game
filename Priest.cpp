#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
		
Priest::Priest(uint id,int x, int y, Team team) : Player(id, x, y, team){HP = 150;}


int Priest::getAttackDamage() const{
	return 0;
}

int Priest::getHealPower() const{
	return 50;
}

int Priest::getMaxHP() const{
	return 150;
}

std::vector<Goal> Priest::getGoalPriorityList(){
	std::vector<Goal> goalPriorityList;
	goalPriorityList.push_back(HEAL);
	goalPriorityList.push_back(TO_ALLY);
	goalPriorityList.push_back(CHEST);
	return goalPriorityList;
}

const std::string Priest::getClassAbbreviation() const{
	if(team==BARBARIANS){
		return "PR";
	}
	else{
		return "pr";
	}
}

std::vector<Coordinate> Priest::getAttackableCoordinates(){
	std::vector<Coordinate> attackableCoordinates;
	return attackableCoordinates;
}

std::vector<Coordinate> Priest::getMoveableCoordinates(){
	std::vector<Coordinate> movableCoordinates;
	movableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));	
	movableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y + 1));
	movableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y + 1));
	movableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y - 1));
	movableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y - 1));
	return movableCoordinates;
}

std::vector<Coordinate> Priest::getHealableCoordinates(){
	std::vector<Coordinate> healableCoordinates;
	healableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	healableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	healableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	healableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));	
	healableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y + 1));
	healableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y + 1));
	healableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y - 1));
	healableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y - 1));
	return healableCoordinates;
}
