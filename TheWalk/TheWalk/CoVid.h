#pragma once
#include "Item.h"

//reprezentant pentru interactiunea cu virusul Covid

class CoVid : public Item
{

public:
	CoVid(Position);
	bool activateCovid(bool);
	void mesaj();
	void mesaj2();
};

