#pragma once
#include <vector>
#include <iostream>
#include <list>
class Bacterium {
protected:
	int x;
	int y;
	int nearby;
	bool isDying{ false };
	char bacteriaName;
public:
	bool isDyingGetter();
	Bacterium(int, int, int);
	Bacterium() = default;
	virtual void checkNearby(std::vector<std::vector<char>>) = 0;
	virtual Bacterium* makeAChild(std::vector<std::vector<char>>&, std::list< Bacterium*>&) = 0;
	bool canIReproduce(std::vector<std::vector<char>>);
	int getX();
	int getY();
	char bacteriaNameGetter();
};

