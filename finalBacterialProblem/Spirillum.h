#pragma once
#include "Bacterium.h"
class Spirillum :
    public Bacterium {
public:
    void checkNearby(std::vector<std::vector<char>>);
    Bacterium* makeAChild(std::vector<std::vector<char>>&, std::list< Bacterium*>&);
    Spirillum(int, int, int);
};

