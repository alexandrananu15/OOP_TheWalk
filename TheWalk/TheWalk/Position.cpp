#include "Position.h"

Position::Position() : line(0), column(0)
{

}

Position::Position(int l, int c) : line(l), column(c)
{

}

Position::Position(const Position& p) : line(p.line), column(p.column)
{
	
}

Position& Position::operator=(const Position& p)
{
	if (&p != this)
	{
		this->line = p.line;
		this->column = p.column;
	}
	return *this;
}

Position& Position::operator+=(const Position& p)
{
	this->line += p.line;
	this->column += p.column;
	return *this;
}

bool Position::operator==(const Position& p)
{
	return (p.line == this->line && p.column == this->column);
}