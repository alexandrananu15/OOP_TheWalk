#include "ThePursuer.h"

#include <iostream>

ThePursuer::ThePursuer(const int maxVieti, Position poz) : Robot(maxVieti, poz)
{

}

int ThePursuer::makeOneStep(vector<Item*> neighbourhood)
{

	std::cout << "The Pursuer s-a mutat de la pozitia " << position.line << ' ' << position.column << " la pozitia ";

	Position attraction = destination;
	for (Item* item : neighbourhood)
		if (item->getType() == ItemType::TELEPORTER or item->getType() == ItemType::THISTLE)
			attraction = item->getPosition();

	//face pasul spre atractia lui
	if (this->position.line < attraction.line)
		this->modifyPosition({ 1, 0 });
	else if (this->position.line > attraction.line)
		this->modifyPosition({ -1, 0 });
	else if (this->position.column < attraction.column)
		this->modifyPosition({ 0, 1 });
	else if (this->position.column > attraction.column)
		this->modifyPosition({ 0, -1 });
	
	std::cout << position.line << " " << position.column << std::endl << std::endl;

	for (Item* item : neighbourhood)
		if (item->getPosition() == this->getPosition())
		{
			if (item->getType() == ItemType::TELEPORTER)
			{
				Teleporter* tel = static_cast<Teleporter*>(item);
				this->setPosition(tel->getTeleport());
				item->toggleState();
				item->mesaj();
				std::cout << "Portalul v-a mutat mai departe pe casuta " << position.line << " " << position.column << std::endl;

			}
			else if (item->getType() == ItemType::BOMB)
			{
				this->modifyHealth(-100);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
				return -1;
			}
			else if (item->getType() == ItemType::BOOSTHEALTH)
			{
				this->modifyHealth(1);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
				
			}
			else if (item->getType() == ItemType::THISTLE)
			{
				this->modifyHealth(-1);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
			}

		}
	
	std::cout << "The Pursuer are acum: " << this->getHealth() << " din " << this->getMaxHealth() << " vieti posibile" << std::endl<<std::endl;

	
	if (!this->isAlive())
	{
		std::cout << "Ai ramas fara vieti! " << std::endl << "GAME OVER! Better luck next time!" <<std::endl;
		return -1;
	}
	if (this->position == destination)
	{
		std::cout << "Ura, ai castigat!" << endl;
		return 10;
	}
	return 1;
}
