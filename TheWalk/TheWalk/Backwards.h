#pragma once
#include "Item.h"

//item reprezentant pentru momentul cand robotul face un pas in spate

class Backwards : public Item
{

public:
	Backwards(Position);
	void mesaj();
};

