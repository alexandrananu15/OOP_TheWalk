#pragma once
#include "Robot.h"

//The Afraid se deplaseaza catre LifeBoosters, insa le poate confunda cu pastile cre genereaza CoronaVirus; se fereste de bombe, ii este foart teama de ele
//interactioneaza cu toti itemii, nu face pasi in spate
//Are un potential de 6 vieti, numarul de vieti este mai mare ptr ca se poate imuniza fata de virusul Corona
//Incepe cu 3 vieti, ca ceilalti roboti
//Este singurul afectat de CoVid

class TheAfraid : public Robot
{
	bool covid;
public:
	TheAfraid(const int, Position);
	void activateCovid(bool);
	int makeOneStep(vector<Item*>);
};

