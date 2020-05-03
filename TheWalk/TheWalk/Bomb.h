#pragma once
#include "Item.h"

//item reprezentant pentru cand lumea este bombardata

class Bomb :public Item
{
	
public:
	Bomb(Position);
	void mesaj() const;
};

