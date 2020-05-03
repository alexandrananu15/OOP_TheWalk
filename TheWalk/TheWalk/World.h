#pragma once
#include <vector>
#include <string>

#include "Item.h"
#include "Bomb.h"
#include "BoostHealth.h"
#include "Teleporter.h"
#include "Thistle.h"
#include "CoVid.h"
#include "Position.h"

class World
{
	int **matrix;
	int noLines;
	int noColumns;
	Position destination;
	std::vector<Item*> items;

public:
	World(int, int);
	~World();
	friend std::ostream	&operator<<(std::ostream&, const World&);
	int getNoLines();
	int getNoColumns();
	Item* getItem(int, int) const;
	void modifyCell(int, Position);
	Position getDestination() const;
	std::vector<Item*> getItemsAround(Position) const;
	bool isOkPosition(Position p) const;
	int getNoLines() const;
	int getNoColumns() const;
	void checkItems();
};

