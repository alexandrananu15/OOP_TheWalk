#include "Item.h"

Item::Item(ItemType it, Position poz) : type(it), itemPos(poz), active(true)
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

Item::~Item()
{
	type = ItemType::NIMIC;
	itemPos = { 0, 0 };
	active = 0;
}