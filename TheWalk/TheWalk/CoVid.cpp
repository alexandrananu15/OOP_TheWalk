#include "CoVid.h"

CoVid::CoVid(Position poz) : Item(" * ", ItemType::COVID, poz)
{

}

bool CoVid::activateCovid(bool state) 
{
	if (state == false)
		this->mesaj();
	else
		this->mesaj2();
	return !state;
}

void CoVid::mesaj() const
{
	std::cout << "Ati fost infectat cu noul CoronaVirus. Din acest moment, la fiecare runda veti pierde cate o viata." << std::endl;
	std::cout << "STAY SAFE";
}

void CoVid::mesaj2() const
{
	std::cout << "Sunteti bolnav de CoronaVirus, dar ajungeti la spital si va imunizati. V-ati vindecat si puteti sa continuati jocul in regim normal" << std::endl;
	std::cout << "STAY SAFE";
}
