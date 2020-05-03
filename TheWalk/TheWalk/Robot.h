#pragma once
#include <vector>
#include "Position.h"
#include "Item.h"
#include "Bomb.h"
#include "BoostHealth.h"
#include "Teleporter.h"
#include "Thistle.h"
#include "CoVid.h"

using namespace std;


class Robot
{
protected:
	int health;								//nr de vieti
	int maxHealth;							//nr de vieti maxim posibil
	Position position;						//pozitia robotului
	const Position destination;				//destinatia unde robotul trebuie sa ajunga
	
public:
	Robot(const int, Position);
	virtual ~Robot() = 0;
	int getHealth() const;
	int getMaxHealth() const;
	Position getPosition() const;
	virtual int makeOneStep(std::vector<Item*>) = 0;
	bool isAlive() const;
	void modifyHealth(int);
	void modifyPosition(Position);
	void setPosition(Position);
	
};

