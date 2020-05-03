#include "Game.h"
#include <iostream>


Game::Game() : robot(NULL), map(NULL), gameStatus(0)
{
	this->beginGame();
}
 
void Game::beginGame()
{
	system("cls");
	std::cout << "Bun venit in taramul magic al roboteilor. Roboteii sunt foarte ocupati si trebuie sa ajunga intr-o anumita destinatie a lumii.";
	std::cout << endl;
	std::cout << "Sa incepem prin a configura proprietatile hartii";
	std::cout << endl;
	this->gameStatus = 1;
	std::cout << "Vreti ca lumea sa fie un patrat cu latura de:... ";
	int n;
	std::cin >> n;
	this->map = new World(n, n);
	std::cout << endl << endl;
	std::cout << "Sa va prezentam robotii:";
	std::cout << endl;
	std::cout << "Robot no. 1: THE PURSUER" << endl;
	std::cout << "Acest robot este neinfricat. Nu este afectat de CoronaVirus si nici nu face pasi in spate." <<endl;
	std::cout << "Isi asuma riscuri, de aceea, de cate ori vede portalul magic, uita de destinatie si se lasa surprins de ce are sa ii ofere viata. " << endl;
	std::cout << "Are un numar de maxim 3 vieti.";
	std::cout << endl << endl;
	std::cout << "Robot no. 2: THE AFRAID" << endl;
	std::cout << "Acest robot este timid si foarte speriat. " << endl;;
	std::cout << "El cunoaste foarte bine locatiile unde sunt bombele, de aceea sansele ca el sa se atinga de una sunt foarte mici. Fiind un ipohondru, cauta mereu serviciile medicale, insa din spitale ppoate prelua virusi periculosi cum ar fi CoronaVirus. " << endl;
	std::cout << "Are un maxim de 6 vieti posibile, insa incepe doar cu 3.";
	std::cout << endl << endl;
	std::cout << "Robot no. 3: THE DRUNK" << endl;
	std::cout << "Acest robot este putin cam ametit. Nu stie unde trebuie sa ajunga si se agata de orice obiect intalneste in cale. " << endl;
	std::cout << "In cazul in care nu gaseste obiecte pe care sa le culeaga, el merge in diagonala pentru ca vrea sa ajunga la mare." << endl;
	std::cout << "Pentru ca nu stie sa inoate, acest lucru ii poate fi fatal. In plus, este singurul robotel care face pasi in spate, cum spuneam, este foarte ametit";
	std::cout << endl << endl;
	
	int x = -1;
	while (x == -1)
	{
		std::cout << "Dati numarul robotelului cu care va veti juca: ";
		std::cin >> x;
		try
		{
			if (x != 1 && x != 2 && x != 3)
				throw - 1;
		}
		catch (int e)
		{
			cout << "Nu ati introdus o tasta valida.";
			x = e;
		}
	}
	switch (x)
	{
		case 1:
		{
			robot = new ThePursuer(3, map->getDestination());	//il construieste cu maxim 3 vieti
			break;
		}
		case 2:
		{
			robot = new TheAfraid(6, map->getDestination());	//il construieste cu maxim 6 vieti
			break;
		}
			case 3:
		{
			robot = new TheDrunk(10, map->getDestination());	//il construieste cu maxim 10 vieti
			break;
		}
	}
	
}

void Game::run()
{
	std::cout << endl;
	system("cls");
	cout << "Va aflati la pozitia 0 0."<< std::endl << std::endl;
	std::cout << *map;												//afisez harta
	std::cout << endl << endl << endl;
	while (gameStatus != -1 && gameStatus != 10)					//daca jocul nu a fost castigat sau pierdut inca, atunci intra in repetitie
	{
		
		int tasta = -1;												//conditia de continuare dupa o runda
		while (tasta == -1)
		{
			std::cout << "Vrei sa te opresti? Apasa tasta 1. Altfel apasa tasta 2." << endl;
			std::cin >> tasta;
			try
			{
				if (tasta != 1 && tasta != 2)
					throw -1;
			}
			catch(int e)
			{
				cout << "Nu ati introdus o tasta valida.";
				tasta = e;
			}
		}

		system("cls");

		map->modifyCell(0, robot->getPosition());							//modifica celula de pe care pleaca robotul si o transforma in spatiu nelocuit
		gameStatus = robot->makeOneStep(map->getItemsAround(robot->getPosition()));				//face un pas
		map->checkItems();																		//odata utilizat, un item este dezactivat
		map->modifyCell(-1, robot->getPosition());												//este mutat robotul pe noua pozitie
		std::cout << *map;																		//este afisata harta
		std::cout << endl << endl << endl;

		if (!map->isOkPosition(robot->getPosition()))											//daca robotul a iesit in afara hartii, a cazut in mare (caz foarte putin probabil, robotii sunt atrasi de itemii care sunt numerosi)
		{
			gameStatus = -1;																	//jocul este pierdut
			std::cout << "L-ati ascultat pe localnicul raufacator cand v-a spus ca locatia dumneavoastra se afla pe o insula de pe mare. Ati parasit taramul magic si ati luat-o inot pe mare. Din pacate, v-ati inecat" <<std::endl;

		}

		if (tasta == 1)										//daca ati apasat 1, asta inseamna ca nu vreti sa continuati
		{
			gameStatus = -1;								//joc incheiat
		}
	}
	std::cout << "Vreti sa mai jucati o data? Daca da, apasati tasta 1. Altfel, apasati orice tasta.";
	int y;
	std::cin >> y;
	if (y == 1)												//incepe un nou joc
	{
		clearGame();
		beginGame();
		run();
	}
}

int Game::getGameStatus()
{
	return gameStatus;
}

void Game::setGameStatus(int status)
{
	gameStatus = status;
}

Robot& Game::getRobot()
{
	return *this->robot;
}

World& Game::getMap()
{
	return *this->map;
}

void Game::clearGame()
{
	delete robot;
	delete map;
	gameStatus = 0;
}

Game::~Game()
{
	clearGame();
}