#include "InputParser.h"

  Game* InputParser::parseGame(){

	unsigned int boardSize, id, maxTurns;
	int x, y, p;
	std::string playerClass, teamStr;
   	Team team;

	std::cin >> boardSize;
	std::cin >> x >> y;
	std::cin >> maxTurns;

	Coordinate chest = {x, y};
	Game *game = new Game(maxTurns, boardSize, chest);

	std::cin >> p;

	for(int i = 0; i<p; i++){
		std::cin >> id >> playerClass >> teamStr >> x >> y;
      if(teamStr=="BARBARIAN"){
         team = BARBARIANS;
      }
      else{
         team = KNIGHTS;
      }
		
		game->addPlayer(id, x, y, team, playerClass);
	}
	return game;
}