#include "Teleporter.h"
#include <iostream>

Teleporter::Teleporter(Position poz, Position tel) : teleport(tel), Item(" T ", ItemType::TELEPORTER, poz)
{

}

void Teleporter::mesaj() const
{
	std::cout << "Pe drumul dumneavoastra ati intalnit un portal magic. Random este cuvantul cheie al zilei. Pregatiti-va sa fiti teleportat oriunde in aceasta lume." << std::endl;
	std::cout << "THE RISK I TOOK WAS CALCULATED, BUT I AM NOT GOOD AT MATHS" << std::endl;
}


Position Teleporter::getTeleport() const
{
	return teleport;
}
