#include "Backwards.h"

Backwards::Backwards(Position poz) : Item(ItemType::BOMB, poz)
{

}

void Backwards::mesaj()
{
	std::cout << "V-ati impiedicat intr-o groapa si ati facut un pas in spate. " << std::endl;
	std::cout << "GAME OVER";
}
