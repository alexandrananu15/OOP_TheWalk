#include "Backwards.h"

Backwards::Backwards(Position poz) : Item(" < ", ItemType::BACKWARDS, poz)
{

}

void Backwards::mesaj() const
{
	std::cout << "V-ati impiedicat intr-o groapa si ati facut un pas in spate. " << std::endl;
	std::cout << "STEP BACK";
}

