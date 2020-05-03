#pragma once
#include "Robot.h"

//The Drunk se deplaseaza catre cel mai apropiat item, fie el capcana sau obiect bun
//Daca nu are itemi in apropiere, atunci se deplaseaza pe diagonala in jos
//interactioneaza cu toati itemii, mai putin cu virusul CoVid, la care este imun
//Are un potential de 10 vieti, insa, nu stie sa inoate, daca ajunge pe marginea hartii, poate cadea in marea ce o inconjoara, murind inecat
//Incepe cu 3 vieti, ca ceilalti roboti
//Este singurul robot care face pasi inapoi

class TheDrunk : public Robot
{
	Position memory;

public:
	TheDrunk(const int, Position);
	int makeOneStep(vector<Item*>);
	Position getMemory() const;
};

