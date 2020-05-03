#include "Item.h"

Item::Item(const char* c, ItemType it, Position poz) : chr(c), type(it), itemPos(poz), active(true)
{

}

Position Item::getPosition() const
{
	return itemPos;
}

ItemType Item::getType() const
{
	return type;
}

void Item::toggleState()
{
	active = !active;
}


bool Item::isActive() const
{
	return active;
}

const char* Item::getCharacter() const
{
	return chr;
}

Item::~Item()
{
	type = ItemType::NIMIC;
	itemPos = { 0, 0 };
	active = 0;
}