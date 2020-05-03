#include "Thistle.h"


Thistle::Thistle(Position poz) : Item(ItemType::THISTLE, poz)
{

}

void Thistle::mesaj()
{
	std::cout << "Ati calcat intr-un ciuline si v-ati pierdut o viata. " << std::endl;
	std::cout << "AOUCH";
}

/*
int Thistle::doSomething(Robot* r)
{
	r->modifyHealth(-1);
	return r->isAlive() ? 1 : -1;
}
*/