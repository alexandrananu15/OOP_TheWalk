#pragma once
#include "Robot.h"

//The Pursuer se deplaseaza catre Portal
//interactioneaza cu toti itemii, insa este imun la Corona datorita curajului iesit din comun, nu face pasi in spate,
//Are un potential de 3 vieti, numarul de vieti este mai mare ptr ca se poate imuniza fata de virusul Corona
//Incepe cu 3 vieti, ca ceilalti roboti
//Desi este robotul cu cele mai putin vieti, are mari sanse de castig

class ThePursuer : public Robot
{

public:
	ThePursuer(const int, Position);
	int makeOneStep(std::vector<Item*>);
};