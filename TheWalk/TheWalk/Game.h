#pragma once
#include "Robot.h"
#include "ThePursuer.h"
#include "TheAfraid.h"
#include "TheDrunk.h"
#include "World.h"
#include <stdlib.h>

class Game 
{
	Robot* robot;				//robotul
	World* map;					//harta
	int gameStatus;				//este 0 daca jocul nu a inceput, 1 cand este in derulare, -1 cand s-a terminat INVINS, 10 cand s-a terminat CASTIGATOR

public:
	Game();
	~Game();
	void beginGame();			//incepe jocul
	void run();					//joaca
	int getGameStatus();
	void setGameStatus(int);
	Robot& getRobot();
	World& getMap();
	void clearGame();
};

