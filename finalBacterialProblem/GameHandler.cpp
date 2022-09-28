#include "GameHandler.h"

int GameHandler::randomGenerator() {
	return rand() % size;
}

void GameHandler::petriDishInitialisation(int number) {
	for (int i = 0; i < number; i++) {
		while (true) {
			int x = randomGenerator();
			int y = randomGenerator();
			if (petriDish[x][y] == '*') {
				petriDish[x][y] = 'B';
				bacteria.push_back(new Bacillus(x, y, 3));
				break;
			}
		}
	}
	for (int i = 0; i < number; i++) {
		while (true) {
			int x = randomGenerator();
			int y = randomGenerator();
			if (petriDish[x][y] == '*') {
				petriDish[x][y] = 'C';
				bacteria.push_back(new Coccus(x, y, 1));
				break;
			}
		}
	}
	for (int i = 0; i < number; i++) {
		while (true) {
			int x = randomGenerator();
			int y = randomGenerator();
			if (petriDish[x][y] == '*') {
				petriDish[x][y] = 'S';
				bacteria.push_back(new Spirillum(x, y, 2));
				break;
			}
		}
	}
}

void GameHandler::showPetriDish() {
	for (int i = 0; i < petriDish.size(); i++) {
		for (int j = 0; j < petriDish[i].size(); j++) {
			std::cout << petriDish[i][j];
		}
		std::cout << std::endl;
	}
}

void GameHandler::passingAway() {
	for (auto i : bacteria) {
		i->checkNearby(petriDish);
	}
}

void GameHandler::updateMap() {
	for (auto i : bacteria) {
		if (i->isDyingGetter()) {
			petriDish[i->getX()][i->getY()] = '*';
		}
	}
}

void GameHandler::updateBacteria() {
	std::vector<std::list<Bacterium*>::iterator> vec;
	for (auto itr = bacteria.begin(); itr != bacteria.end(); itr++) {
		if ((*itr)->isDyingGetter()) {
			vec.push_back(itr);
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		bacteria.erase(vec[i]);
	}
}

void GameHandler::reproduction() {
	std::vector<Bacterium*> vec;
	for (auto itr = bacteria.begin(); itr != bacteria.end(); itr++) {
		if ((*itr)->canIReproduce(petriDish)) {
			vec.push_back((*itr)->makeAChild(petriDish, bacteria));
		}
	}
	for (auto i : vec) {
		bacteria.push_back(i);
	}
}

void GameHandler::lifeCourse() {
	int lastB, lastC, lastS;
	petriDishInitialisation(numberOfBacteria);
	showPetriDish();
	countBacteria();
	lastB = bacillus;
	lastC = coccus;
	lastS = spirillum;
	std::cout << "INITIALISATION OF THE PETRI DISH\n";
	std::cout << "Round number " << 0 << "\n";
	std::cout << "Bacillus:  " << bacillus << std::endl;
	std::cout << "Coccus:  " << coccus << std::endl;
	std::cout << "Spirillum:  " << spirillum << std::endl;
	std::cout << "\nPress anything to continue";
	_getch();
	int i = 1; 
	while (true) {
		system("CLS");
		
		passingAway();
		updateMap();
		updateBacteria();
		
		showPetriDish();
		countBacteria();
		std::cout << "Bacteria are dying\n";
		std::cout << "Round number " << i << "\n";
		std::cout << "Bacillus:  " << bacillus <<"  || Dead bacteria:"<<lastB-bacillus<< std::endl;
		std::cout << "Coccus:  " << coccus << "  || Dead bacteria:" << lastC - coccus << std::endl;
		std::cout << "Spirillum:  " << spirillum << "  || Dead bacteria:" << lastS - spirillum << std::endl;
		std::cout << "\nPress anything to continue";
		lastB = bacillus;
		lastC = coccus;
		lastS = spirillum;
		_getch();
		system("CLS");

		reproduction();
		showPetriDish();
		countBacteria();
		std::cout << "Bacteria are beeing born";
		std::cout << "Round number " << i << "\n";
		std::cout << "Bacillus:  " << bacillus << "  || New borns:" << bacillus -lastB  << std::endl;
		std::cout << "Coccus:  " << coccus << "  || New borns:" << coccus - lastC << std::endl;
		std::cout << "Spirillum:  " << spirillum << "  || New borns:" << spirillum - lastS << std::endl;
		std::cout << "\nPress anything to continue";
		_getch();
		i++;
		lastB = bacillus;
		lastC = coccus;
		lastS = spirillum;
	}
}

void GameHandler::countBacteria() {
	bacillus = 0;
	coccus = 0;
	spirillum = 0;
	for (auto i : bacteria) {
		if (i->bacteriaNameGetter() == 'B') {
			bacillus++;
		}
		if (i->bacteriaNameGetter() == 'C') {
			coccus++;
		}
		if (i->bacteriaNameGetter() == 'S') {
			spirillum++;
		}
	}
}

GameHandler::GameHandler(int Size,int NumberOfBacteria) {
	size = Size;
	numberOfBacteria = NumberOfBacteria;
	petriDish = std::vector<std::vector<char>>(size, std::vector<char>(size, '*'));
}

