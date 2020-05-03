#include "Bomb.h"


Bomb::Bomb(Position poz) : Item(" X ", ItemType::BOMB, poz)
{

}

void Bomb::mesaj() const
{
	std::cout << "Ati calcat pe o bomba. Din pacate intreg tinutul este aruncat in aer." << std::endl;
	std::cout << "GAME OVER";
}

