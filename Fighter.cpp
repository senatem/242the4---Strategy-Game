#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Fighter::Fighter(uint id,int x, int y, Team team) : Player(id, x, y, team){HP = 400;}

int Fighter::getAttackDamage() const{
	return 100;
}

int Fighter::getHealPower() const{
	return 0;
}

int Fighter::getMaxHP() const{
	return 400;
}

std::vector<Goal> Fighter::getGoalPriorityList(){
	std::vector<Goal> goalPriorityList;
	goalPriorityList.push_back(ATTACK);
	goalPriorityList.push_back(TO_ENEMY);
	goalPriorityList.push_back(CHEST);
	return goalPriorityList;
}

const std::string Fighter::getClassAbbreviation() const{
	if(team==BARBARIANS){
		return "FI";
	}
	else{
		return "fi";
	}
}

std::vector<Coordinate> Fighter::getAttackableCoordinates(){
	std::vector<Coordinate> attackableCoordinates;
	attackableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));
	attackableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	return attackableCoordinates;
}

std::vector<Coordinate> Fighter::getMoveableCoordinates(){
	std::vector<Coordinate> movableCoordinates;
	movableCoordinates.push_back(Coordinate(coordinate.x - 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x + 1, coordinate.y));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y - 1));
	movableCoordinates.push_back(Coordinate(coordinate.x, coordinate.y + 1));
	return movableCoordinates;
}

std::vector<Coordinate> Fighter::getHealableCoordinates(){
	std::vector<Coordinate> healableCoordinates;
	return healableCoordinates;
}
