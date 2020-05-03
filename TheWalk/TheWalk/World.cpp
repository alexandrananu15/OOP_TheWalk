#include "World.h"
#include <iostream>


World::World(int l, int c) : noLines(l), noColumns(c), 
destination(rand() % noLines, rand() % noColumns)
{
	matrix = new int* [noLines];
	for (int i = 0; i < noLines; ++i)
	{
		matrix[i] = new int[noColumns];
		std::fill(matrix[i], matrix[i] + noColumns, 0);
	}
	matrix[0][0] = -1;									//marcam robotul cu -1
	matrix[destination.line][destination.column] = -2;	//marcam destinatia finala cu -2

	//generez itemi
	for (int i = 0; i < noLines; ++i)
		for (int j = 0; j < noColumns; ++j)
		{
			int procent = rand() % 100;
			if (i + j == 0) continue;
			if (i == destination.line && j == destination.column) continue;

			if (procent < 10)
			{
				items.push_back(new BoostHealth({ i, j }));
				matrix[i][j] = items.size() - 1;
			}
			else if (procent < 15)
			{
				items.push_back(new Bomb({ i, j }));
				matrix[i][j] = items.size() - 1;
			}
			else if (procent < 25)
			{
				items.push_back(new Teleporter({ i, j }, { rand() % noLines, rand() % noColumns }));
				matrix[i][j] = items.size() - 1;
			}
			else if (procent < 35)
			{
				items.push_back(new Thistle({ i, j }));
				matrix[i][j] = items.size() - 1;
			}
			else if (procent < 45)
			{
				items.push_back(new CoVid({ i, j }));
				matrix[i][j] = items.size() - 1;
			}
			else if (procent < 55)
			{
				items.push_back(new CoVid({ i, j }));
				matrix[i][j] = items.size() - 1;
			}
		}
};

World::~World()
{
	for (int i = 0; i < noLines; ++i)
		delete[]matrix[i];
	delete[]matrix;
	noLines = noColumns = 0;
}

std::ostream& operator<<(std::ostream& out, const World& harta)
{
	for (int i = 0; i < harta.noLines; ++i)
	{
		for (int j = 0; j < harta.noColumns; ++j)
		{
			if (harta.matrix[i][j] == -1)
				out << " @ ";				
			else if (harta.matrix[i][j] == -2)
				out << " $ ";
			else if (harta.getItem(i, j))
			{
				if (harta.getItem(i, j)->getType() == ItemType::TELEPORTER)
					out << " T ";
				else if (harta.getItem(i, j)->getType() == ItemType::BOMB)
					out << " X ";
				else if (harta.getItem(i, j)->getType() == ItemType::BOOSTHEALTH)
					out << " + ";
				else if (harta.getItem(i, j)->getType() == ItemType::THISTLE)
					out << " # ";
				else if (harta.getItem(i, j)->getType() == ItemType::COVID)
					out << " * ";
				else if (harta.getItem(i, j)->getType() == ItemType::BACKWARDS)
					out << " < ";
			}
			else
				out << "   ";

		}
		out << std::endl;
	}
	return out;
}

void World::modifyCell(int value, Position poz)
{
	if(isOkPosition(poz))
		matrix[poz.line][poz.column] = value;
}

int World::getNoLines()
{
	return noLines;
}

int World::getNoColumns()
{
	return noColumns;
}

Item* World::getItem(int l, int c) const
{
	if (matrix[l][c] > 0)
		return items[matrix[l][c]];
	return NULL;
}

Position World::getDestination() const
{
	return destination;
}

bool World::isOkPosition(Position p) const
{
	if (p.line >= 0 && p.line < noLines && p.column >= 0 && p.column < noColumns)
		return true;
	return false;
}

std::vector<Item*> World::getItemsAround(Position poz) const
{
	std::vector <Item*> around;
	if (isOkPosition({ poz.line + 1, poz.column }) && getItem(poz.line + 1, poz.column))
		around.push_back(getItem(poz.line + 1, poz.column));
	if (isOkPosition({ poz.line, poz.column + 1}) && getItem(poz.line, poz.column + 1))
		around.push_back(getItem(poz.line, poz.column + 1));
	if (isOkPosition({ poz.line - 1, poz.column }) && getItem(poz.line - 1, poz.column))
		around.push_back(getItem(poz.line - 1, poz.column));
	if (isOkPosition({ poz.line, poz.column - 1 }) && getItem(poz.line, poz.column - 1))
		around.push_back(getItem(poz.line, poz.column - 1));
	return around;
}

int World::getNoLines() const
{
	return noLines;
}

int World::getNoColumns() const
{
	return noColumns;
}

void World::checkItems()
{
	for (int i = 0; i < noLines; i++)
		for (int j = 0; j < noColumns; j++)
			if (matrix[i][j] > 0)
			{
				Item* curent;
				curent = getItem(i, j);
				if (curent != NULL && !curent->isActive())
				{
					matrix[i][j] = 0;
				}
			}
}