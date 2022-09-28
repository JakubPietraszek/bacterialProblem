#pragma once
#include "Bacillus.h"
#include "Coccus.h"
#include "Spirillum.h"
#include <list>
#include <conio.h>
class GameHandler {
	int size;
	int numberOfBacteria;
	std::vector<std::vector<char>> petriDish;
	std::list<Bacterium*> bacteria;
	int bacillus{};
	int coccus{};
	int spirillum{};
	int randomGenerator();
	void petriDishInitialisation(int);
	void showPetriDish();
	void passingAway();
	void updateMap();
	void updateBacteria();
	void reproduction();
	void countBacteria();
public:
	void lifeCourse();
	GameHandler(int,int);
	GameHandler() = default;
};

