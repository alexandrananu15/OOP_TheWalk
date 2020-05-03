#pragma once
#include "Position.h"
#include <iostream>

enum class ItemType
{
	BACKWARDS, BOMB, TELEPORTER, THISTLE, BOOSTHEALTH, COVID, NIMIC
};


class Item
{
	const char* chr;
protected:
	ItemType type;				
	Position itemPos;			//pozitia itemului
	bool active;				//indica daca itemul este activ sau nu
public:
	Item(const char*, ItemType, Position);
	virtual ~Item() = 0;
	Position getPosition() const;
	virtual void mesaj() const = 0;
	ItemType getType() const;
	void toggleState();
	bool isActive() const;
	const char* getCharacter() const;
};

