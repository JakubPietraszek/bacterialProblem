#pragma once
#include "Bacterium.h"
class Coccus :
    public Bacterium {
public:
    void checkNearby(std::vector<std::vector<char>>);
    Bacterium* makeAChild(std::vector<std::vector<char>>&, std::list< Bacterium*>&);
    Coccus(int, int, int);
};

