#include "Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Player::Player(): id(0), coordinate(0,0){}

Player::Player(unsigned int id,int x, int y, Team team):
	coordinate(x,y),
	id(id),
	team(team)
{
}

unsigned int Player::getID() const{
	return id;
}

const Coordinate& Player::getCoord() const{
	return coordinate;
}

int Player::getHP() const{
	return HP;
}

Team Player::getTeam() const{
	return team;
}

std::string Player::getBoardID(){
	std::string boardID = std::to_string(id);
	if(boardID.std::string::length()==1){
		boardID = "0" + boardID;
	}
	return boardID;
}

bool Player::attack(Player *enemy){
	enemy->isAttacked(this->getAttackDamage());
	std::cout << "Player " << this->getBoardID() << " attacked Player " << enemy->getBoardID() << " (" << this->getAttackDamage() << ")" << std::endl;

	if(enemy->isDead()){
		return true;
	}
	else{
		return false;
	}
}

void Player::heal(Player *ally){
	ally->isHealed(this->getHealPower());
	std::cout << "Player " << this->getBoardID() << " healed Player " << ally->getBoardID() << std::endl;
}

void Player::movePlayerToCoordinate(Coordinate c){
	std::cout << "Player " << this->getBoardID() << " moved from " << coordinate << " to " << c << std::endl;
	coordinate = c;
}

bool Player::isDead() const{
	if(HP <= 0){
		return true;
	}
	return false;
}

void Player::isAttacked(int attackPower){
	HP = HP - attackPower;
}

void Player::isHealed(int healPower){
	HP = HP + healPower;
	if(HP >= getMaxHP()){
		HP = getMaxHP();
	}
}