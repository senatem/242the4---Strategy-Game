#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Tank::Tank(uint id,int x, int y, Team team) : Player(id, x, y, team){HP = 1000;}

int Tank::getAttackDamage() const{
	return 25;
}

int Tank::getHealPower() const{
	return 0;
}

int Tank::getMaxHP() const{
	return 1000;
}

std::vector<Goal> Tank::getGoalPriorityList(){
	std::vector<Goal> goalPriorityList;
	goalPriorityList.push_back(TO_ENEMY);
	goalPriorityList.push_back(ATTACK);
	goalPriorityList.push_back(CHEST);
	return goalPriorityList;
}

const std::string Tank::getClassAbbreviation() const{
	if(team==BARBARIANS){
		return "TA";
	}
	else{
		return "ta";
	}
}

std::vector<Coordinate> Tank::getAttackableCoordinates(){
	std::vector<Coordinate> attackableCoordinates;
	attackableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));	
	return attackableCoordinates;
}

std::vector<Coordinate> Tank::getMoveableCoordinates(){
	std::vector<Coordinate> movableCoordinates;
	movableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));	
	return movableCoordinates;
}

std::vector<Coordinate> Tank::getHealableCoordinates(){
	std::vector<Coordinate> healableCoordinates;
	return healableCoordinates;
}
