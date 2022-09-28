#pragma once
#include "Bacterium.h"
class Bacillus :
    public Bacterium {
public:
    void checkNearby(std::vector<std::vector<char>>);
    Bacterium* makeAChild(std::vector<std::vector<char>>&, std::list< Bacterium*>&);
    Bacillus(int X, int Y, int Nearby);

};

