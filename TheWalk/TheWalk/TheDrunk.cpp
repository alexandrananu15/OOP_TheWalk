#include "TheDrunk.h"

//The Drunk se deplaseaza catre cel mai apropiat item, fie el capcana sau obiect bun
//Daca nu are itemi in apropiere, atunci se deplaseaza pe diagonala in jos
//interactioneaza cu toati itemii, mai putin cu virusul CoVid, la care este imun
//Are un potential de 10 vieti, insa, nu stie sa inoate, daca ajunge pe marginea hartii, poate cadea in marea ce o inconjoara, murind inecat
//Incepe cu 3 vieti, ca ceilalti roboti
//Este singurul robot care face pasi inapoi


TheDrunk::TheDrunk(const int maxVieti, Position poz) : memory({0, 0}), Robot(maxVieti, poz)		//initial se afla pe pozitia 0, 0
{

}

int TheDrunk::makeOneStep(vector<Item*> neighbourhood)
{
	memory = position;					//retinem ultimul pas

	std::cout << "The Drunk s-a mutat de la pozitia " << position.line << ' ' << position.column << " la pozitia ";

	Position attraction = Position({ position.line +1, position.column + 1 });			//attraction este pozitia catre care se indreapta
	for (Item* item : neighbourhood)					//itemii din jurul lui (stanga, sus, dreapta, jos)
			attraction = item->getPosition();			//ultiml item gasit vizualizat este cel care il va atrage 

	//se misca spre un item si, daca nu, in diagonala
	if (this->position.line < attraction.line && this->position.column < attraction.column)
		this->modifyPosition({ 1, 1 });
	else if (this->position.line > attraction.line && this->position.column > attraction.column)
		this->modifyPosition({ 1, 1 });
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
		if (item->getPosition() == this->getPosition())				//urmarim sa vedem pe ce item a nimerit
		{
			if (item->getType() == ItemType::TELEPORTER)			//il teleporteaza
			{
				Teleporter* tel = static_cast<Teleporter*>(item);
				this->setPosition(tel->getTeleport());
				item->toggleState();
				item->mesaj();
				std::cout << "Portalul v-a mutat mai departe pe casuta " << position.line << " " << position.column << std::endl;
				std::cout << std::endl;

			}
			else if (item->getType() == ItemType::BOMB)				//finalizeaza jocul
			{
				this->modifyHealth(-100);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
				return -1;
			}
			else if (item->getType() == ItemType::BOOSTHEALTH)		//o viata in plus
			{
				this->modifyHealth(1);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;

			}
			else if (item->getType() == ItemType::THISTLE)			//o viata in minus
			{
				this->modifyHealth(-1);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
			}
			else if (item->getType() == ItemType::BACKWARDS)		//un pas in spate
			{
				this->setPosition(memory);
				item->toggleState();
				item->mesaj();
				std::cout << std::endl;
				std::cout << "V-ati mutat inapoi pe pozitia " << position.line << " " << position.column << std::endl;
			}

		}

	std::cout << "The Drunk are acum: " << this->getHealth() << " din " << this->getMaxHealth() << " vieti posibile" << std::endl << std::endl;


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

Position TheDrunk::getMemory() const
{
	return memory;
}