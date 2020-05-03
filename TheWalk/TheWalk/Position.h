#pragma once

struct Position
{
	int line, column;
	Position();
	Position(int, int);
	Position(const Position&);
	Position& operator=(const Position&);
	Position& operator+=(const Position&);
	bool operator==(const Position&);
};

