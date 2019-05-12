#include"Game.h"
#include"InputParser.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Game::Game(unsigned int maxTurnNumber, unsigned int boardSize, Coordinate chest):
	maxTurnNumber(maxTurnNumber),
	players(),
	board(boardSize, &players, chest)
{
	turnNumber = 0;
}

Game::~Game(){
	for(int i=0; i<players.size(); i++){
		delete players.at(i);
	}
	delete this;
}

void Game::addPlayer(int id, int x, int y, Team team, std::string _class){
	if(_class=="ARCHER"){
		Player *player = new Archer(id, x, y, team);
		players.push_back(player);
	}
	else if(_class=="FIGHTER"){
		Player *player = new Fighter(id, x, y, team);
		players.push_back(player);
	}
	else if(_class=="PRIEST"){
		Player *player = new Priest(id, x, y, team);
		players.push_back(player);
	}
	else if(_class=="SCOUT"){
		Player *player = new Scout(id, x, y, team);
		players.push_back(player);
	}
	else if(_class=="TANK"){
		Player *player = new Tank(id, x, y, team);
		players.push_back(player);
	}
	sortPlayers();
}

bool Game::isGameEnded(){
	bool barbariansDead = true;
	bool barbariansGotChest = false;
	bool knightsDead = true;
	
	for(int i=0; i<players.size(); i++){
		if(players[i]->getTeam()==BARBARIANS){
			barbariansDead = false;
			barbariansGotChest = barbariansGotChest || (players[i]->getCoord() == board.getChestCoordinates());
		}
		else{
			knightsDead = false;
		}
	}

	if(barbariansDead){
		std::cout << "Game ended at turn " << turnNumber << ". All barbarians dead. Knight victory." << std::endl;
		return true;
	}
	if(knightsDead){
		std::cout << "Game ended at turn " << turnNumber << ". All knights dead. Barbarian victory." << std::endl;
		return true;
	}
	if(barbariansGotChest){
		std::cout << "Game ended at turn " << turnNumber << ". Chest captured. Barbarian victory." << std::endl;
		return true;
	}
	if(turnNumber==maxTurnNumber){
		std::cout << "Game ended at turn " << turnNumber << ". Maximum turn number reached. Knight victory." << std::endl;
		return true;
	}
	return false;
}

void Game::playTurn(){
	turnNumber++;
	std::cout << "Turn " << turnNumber << " has started." << std::endl;
	std::vector<int> deadList;
	Goal goal;
	for(int i=0; i<players.size(); i++){
		if(players[i]->isDead()){
			std::cout << "Player " << players[i]->getBoardID() << " has died." << std::endl;
			deadList.push_back(i);
		}
		else{
			goal = playTurnForPlayer(players[i]);}
		// if(goal == ATTACK){
		// 	std::cout << "goal: ATTACK" << std::endl;
		// }
		// else if(goal == HEAL){
		// 	std::cout << "goal: HEAL" << std::endl;
		// }
		// else if(goal == TO_ALLY){
		// 	std::cout << "goal: TO_ALLY" << std::endl;
		// }
		// else if(goal == TO_ENEMY){
		// 	std::cout << "goal: TO_ENEMY" << std::endl;
		// }
		// else if(goal == CHEST){
		// 	std::cout << "goal: CHEST" << std::endl;}
		// else if(goal == NO_GOAL){
		// 	std::cout << "goal: NO_GOAL" << std::endl;
		// }
	}
		
	for(int i=0; i<deadList.size(); i++){

		delete players.at(deadList[i]);
		players.erase(players.begin()+deadList[i]);
	}
}

Goal Game::playTurnForPlayer(Player* player){

	std::vector<Goal> goals = player->getGoalPriorityList();
	for(int i=0; i<goals.size(); i++){
		if(goals[i] == ATTACK){
			//attack
			std::vector<Coordinate> attackable = player->getAttackableCoordinates();
			for(int k=0; k<players.size(); k++){
				for(int j=0; j<attackable.size(); j++){
					if(players[k]->getCoord()==attackable[j]){
						if(player->getTeam() != players[k]->getTeam() && !players[k]->isDead()){
							player->attack(players[k]);
							return ATTACK;
						}
					}
				}
			}
		}
		else if(goals[i] == CHEST){
				//move to chest
				std::vector<Coordinate> moveable = player->getMoveableCoordinates();
				std::vector<int> distances;
				std::vector<std::string> directions;
				int d;
				int mind = 2*board.getBoardSize();

				//!board.isPlayerOnCoordinate(board.getChestCoordinates()) || (player->getCoord() - board.getChestCoordinates() > 1)
				if(player->getCoord() != board.getChestCoordinates() && !(board.isPlayerOnCoordinate(board.getChestCoordinates()) && player->getCoord() - board.getChestCoordinates() == 1 )){
					for(int j=0; j<moveable.size(); j++){
						bool notBlocked = board.isCoordinateInBoard(moveable[j]) && !board.isPlayerOnCoordinate(moveable[j]);

						d = moveable[j]-board.getChestCoordinates();
						if(d<mind && notBlocked){
							mind=d;

						}
						if(player->getCoord()-moveable[j]==2 && notBlocked){
							directions.push_back("DIAGONAL");
						}
						else if(abs(player->getCoord().x - moveable[j].x)==1 && notBlocked){
							directions.push_back("HORIZONTAL");
						}
						else if(abs(player->getCoord().y - moveable[j].y)==1 && notBlocked){
							directions.push_back("VERTICAL");
						}
						else{
							directions.push_back("BLOCKED");
						}
						distances.push_back(d);
					}
					for(int j=0; j<moveable.size(); j++){

						if(distances[j] == mind && directions[j] == "DIAGONAL"){

							player->movePlayerToCoordinate(moveable[j]);
							return CHEST;
						}
						else if(distances[j] == mind && directions[j] == "HORIZONTAL"){
							player->movePlayerToCoordinate(moveable[j]);
							return CHEST;
						}
						else if(distances[j] == mind && directions[j] == "VERTICAL"){
							player->movePlayerToCoordinate(moveable[j]);
							return CHEST;
						}
					}
				}
		}
		else if(goals[i] == TO_ENEMY){
				//move to enemy

				std::vector<int> enemyDistances;
				std::vector<Coordinate> moveable = player->getMoveableCoordinates();
				std::vector<int> distances;
				std::vector<std::string> directions;
				int d, target;
				int mind = board.getBoardSize();

				for(int j=0; j<players.size(); j++){
					if(players[j]->getTeam()!=player->getTeam()){
						d = player->getCoord()-players[j]->getCoord();
						if(d<mind){
							mind=d;
						}
						enemyDistances.push_back(d);

					}
					else{
						enemyDistances.push_back(0);
					}
				}

				for(int j=0; j<players.size(); j++){
					if(enemyDistances[j]!=0 && enemyDistances[j] == mind){
						target = j;
						break;
					}
				}
				
				mind = board.getBoardSize();

				for(int j=0; j<moveable.size(); j++){
					d = moveable[j]-players[target]->getCoord();
					if(d<mind){
						mind=d;
					}
					if(player->getCoord()-moveable[j]==2){
						directions.push_back("DIAGONAL");
					}
					else if(abs(player->getCoord().x - moveable[j].x)==1){
						directions.push_back("HORIZONTAL");
					}
					else{
						directions.push_back("VERTICAL");
					}
					distances.push_back(d);
				}
				for(int j=0; j<moveable.size(); j++){
					bool notBlocked = board.isCoordinateInBoard(moveable[j]) && !board.isPlayerOnCoordinate(moveable[j]);
					if(distances[j] == mind && directions[j] == "DIAGONAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ENEMY;
					}
					else if(distances[j] == mind && directions[j] == "HORIZONTAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ENEMY;
					}
					else if(distances[j] == mind && directions[j] == "VERTICAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ENEMY;
					}
				}
		}
		else if(goals[i] == TO_ALLY){
				//move to ally
				std::vector<int> allyDistances;
				std::vector<Coordinate> moveable = player->getMoveableCoordinates();
				std::vector<int> distances;
				std::vector<std::string> directions;
				int d, target;
				int mind = board.getBoardSize();

				for(int j=0; j<players.size(); j++){
					if(players[j]->getTeam()==player->getTeam() && player!=players[j]){
						d = player->getCoord()-players[j]->getCoord();

						if(d<mind){
							mind=d;
						}
						allyDistances.push_back(d);
					}
					else{
						allyDistances.push_back(0);
					}
				}
				for(int j=0; j<players.size(); j++){
					if(allyDistances[j]!=0 && allyDistances[j] == mind){
						target = j;
						break;
					}
					else{
						target = -1;
					}
				}

				mind = board.getBoardSize();
				if(target!=-1){
				for(int j=0; j<moveable.size(); j++){
					d = moveable[j]-players[target]->getCoord();
					if(d<mind){
						mind=d;
					}
					if(player->getCoord()-moveable[j]==2){
						directions.push_back("DIAGONAL");
					}
					else if(abs(player->getCoord().x - moveable[j].x)==1){
						directions.push_back("HORIZONTAL");
					}
					else{
						directions.push_back("VERTICAL");
					}
					distances.push_back(d);
				}
				for(int j=0; j<moveable.size(); j++){
					bool notBlocked = board.isCoordinateInBoard(moveable[j]) && !board.isPlayerOnCoordinate(moveable[j]);
					if(distances[j] == mind && directions[j] == "DIAGONAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ALLY;
					}
					else if(distances[j] == mind && directions[j] == "HORIZONTAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ALLY;
					}
					else if(distances[j] == mind && directions[j] == "VERTICAL" && notBlocked){
						player->movePlayerToCoordinate(moveable[j]);
						return TO_ALLY;
					}
				}
			}
		}
		else if(goals[i] == HEAL){
				//heal
				std::vector<Coordinate> healable = player->getHealableCoordinates();
				int healed=0;
				for(int k=0; k<players.size(); k++){
					for(int j=0; j<healable.size(); j++){
						if(players[k]->getCoord()==healable[j]){

							if(player->getTeam() == players[k]->getTeam()){

								player->heal(players[k]);
								healed++;
							}
						}
					}
				}
				if(healed!=0){
					return HEAL;
				}
		}
	}
	return NO_GOAL;
}

void Game::sortPlayers(){
	int num = players.size();
	Player *tmp;
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(players[i]->getID() > players[j]->getID()){
				tmp = players[i];
				players[i] = players[j];
				players[j] = tmp;

			}
		}
	}
}