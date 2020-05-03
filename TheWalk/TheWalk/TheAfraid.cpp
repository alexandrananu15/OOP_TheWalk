#include "TheAfraid.h"

//The Afraid se deplaseaza catre LifeBoosters, insa le poate confunda cu pastile cre genereaza CoronaVirus; se fereste de bombe, ii este foart teama de ele
//interactioneaza cu toti itemii, nu face pasi in spate
//Are un potential de 6 vieti, numarul de vieti este mai mare ptr ca se poate imuniza fata de virusul Corona
//Incepe cu 3 vieti, ca ceilalti roboti
//Este singurul afectat de CoVid


TheAfraid::TheAfraid(const int maxVieti, Position poz) : covid(false), Robot(maxVieti, poz)
{

}

void TheAfraid::activateCovid(bool state)
{
	covid = state;
}


int TheAfraid::makeOneStep(vector<Item*> neighbourhood)
{
	std::cout << "The Afraid s-a mutat de la pozitia " << position.line << ' ' << position.column << " la pozitia ";

	Position attraction = destination;				//se indreapta spre destinatie, atata timp cat in preajma nu se alfla un lifeBooster
													//confunda lifeBoosterele cu pastile generatoare de Corona
	ItemType tip = ItemType::NIMIC;
	for (Item* item : neighbourhood)
		if (item->getType() == ItemType::BOOSTHEALTH || item->getType() == ItemType::COVID)
		{
			attraction = item->getPosition();
			tip = item->getType();
		}

	if (this->position.line < attraction.line && tip != ItemType::BOMB)				//prima grija este sa se fereasca de bombe
		this->modifyPosition({ 1, 0 });
	else if (this->position.line > attraction.line && tip != ItemType::BOMB)
		this->modifyPosition({ -1, 0 });
	else if (this->position.column < attraction.column  && tip != ItemType::BOMB)
		this->modifyPosition({ 0, 1 });
	else if (this->position.column > attraction.column  && tip != ItemType::BOMB)
		this->modifyPosition({ 0, -1 });
	else if (this->position.line < attraction.line)
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
			if (item->getType() == ItemType::TELEPORTER)				//il teleporteaza undeva random pe harta din pozitia actuala
			{
				Teleporter* tel = static_cast<Teleporter*>(item);
				this->setPosition(tel->getTeleport());
				item->toggleState();
				item->mesaj();
				std::cout << "Portalul v-a mutat mai departe pe casuta " << position.line << " " << position.column << std::endl;
				std::cout << std::endl;

			}
			else if (item->getType() == ItemType::BOMB)					//termina jocul
			{
				this->modifyHealth(-100);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
				return -1;
			}
			else if (item->getType() == ItemType::BOOSTHEALTH)			//ii da o viata in plus
			{
				this->modifyHealth(1); 
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;

			}
			else if (item->getType() == ItemType::THISTLE)				//ii scade o viata
			{
				this->modifyHealth(-1);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
			}
			else if (item->getType() == ItemType::COVID)				//il imbolnaveste de Corona sau il face bine
			{
				CoVid* bh = static_cast<CoVid*>(item);
				item->toggleState();
				this->activateCovid(bh->activateCovid(covid));
				std::cout << std::endl;
			}

		}

	if (covid)
	{
		this->modifyHealth(-1);
	}

	std::cout << "The Afraid are acum: " << this->getHealth() << " din " << this->getMaxHealth() << " vieti posibile" << std::endl << std::endl;
	

	if (!this->isAlive())
	{
		std::cout << "Ai ramas fara vieti! " << std::endl << "GAME OVER! Better luck next time!" << std::endl;
		return -1;
	}
	if (this->position == destination)
	{
		std::cout << "Ura, ai castigat!" << endl;
		return 10;
	}
	return 1;
}