#include "BoostHealth.h"


BoostHealth::BoostHealth(Position poz) : Item(" + ", ItemType::BOOSTHEALTH, poz)
{

}

void BoostHealth::mesaj()
{
	std::cout << "V-ati intalnit cu zana cea buna din tinut. Domnisoara va binecuvanteaza si primiti o viata in plus pentru curajul dumneavoastra." << std::endl;
	std::cout << "KEEP IT UP";
}
