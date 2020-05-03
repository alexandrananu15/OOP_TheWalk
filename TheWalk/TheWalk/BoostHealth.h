#pragma once
#include "Item.h"

//reprezentant pentru adaugarea unei noi vieti

class BoostHealth : public Item
{

public:
	BoostHealth(Position);
	void mesaj();
};

