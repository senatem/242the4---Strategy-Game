#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Scout::Scout(uint id,int x, int y, Team team) : Player(id, x, y, team){HP = 125;}


int Scout::getAttackDamage() const{
	return 25;
}

int Scout::getHealPower() const{
	return 0;
}

int Scout::getMaxHP() const{
	return 125;
}

std::vector<Goal> Scout::getGoalPriorityList(){
	std::vector<Goal> goalPriorityList;
	goalPriorityList.push_back(CHEST);
	goalPriorityList.push_back(TO_ALLY);
	goalPriorityList.push_back(ATTACK);
	return goalPriorityList;
}

const std::string Scout::getClassAbbreviation() const{
	if(team==BARBARIANS){
		return "SC";
	}
	else{
		return "sc";
	}
}

std::vector<Coordinate> Scout::getAttackableCoordinates(){
	std::vector<Coordinate> attackableCoordinates;
	attackableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));	
	attackableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y + 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y + 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y - 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y - 1));
	return attackableCoordinates;
}

std::vector<Coordinate> Scout::getMoveableCoordinates(){
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

std::vector<Coordinate> Scout::getHealableCoordinates(){
	std::vector<Coordinate> healableCoordinates;
	return healableCoordinates;
}
