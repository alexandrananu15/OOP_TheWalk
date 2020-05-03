#pragma once
#include "Item.h"

//reprezentant pentru portal: te teleporteaza oriunde pe harta

class Teleporter : public Item
{
	Position teleport;

public:
	Teleporter(Position, Position);
	void mesaj();
	Position getTeleport() const;
};

