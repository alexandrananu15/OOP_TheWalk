#include "Robot.h"

Robot::Robot(const int noMaxLives, Position poz) : health(3), maxHealth(noMaxLives), position(), destination(poz)
{

}

Robot::~Robot()
{
	health = 0;
	maxHealth = 0;
}

int Robot::getHealth() const
{
	return health;
}

int Robot::getMaxHealth() const
{
	return maxHealth;
}

Position Robot::getPosition() const
{
	return position;
}

bool Robot::isAlive() const
{
	return health > 0;
}


void Robot::modifyHealth(int life)
{
	health += life;
	if (health > maxHealth)
		health = maxHealth;
	else if (health < 0)
		health = 0;
}


void Robot::modifyPosition(Position p)
{
	this->position += p;
}

void Robot::setPosition(Position p)
{
	this->position = p;
}
