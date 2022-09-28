#include "Bacterium.h"
bool Bacterium::isDyingGetter()
{
    return isDying;
}
Bacterium::Bacterium(int X, int Y, int Nearby) {
    x = X;
    y = Y;
    nearby = Nearby;   
}

int Bacterium::getX() {
    return x;
}

int Bacterium::getY() {
    return y;
}

char Bacterium::bacteriaNameGetter() {
    return bacteriaName;
}

bool Bacterium::canIReproduce(std::vector<std::vector<char>> petriDish) {

    for (int i = getX() - nearby; i <= getX() + nearby; i++) {
        for (int j = getY() - nearby; j <= getY() + nearby; j++) {

            if (i < 0 || i >= petriDish.size() || j < 0 || j >= petriDish.size())
                continue;
            if (petriDish[i][j] == '*')
            {
                return true;
            }

        }
    }
    return false;
}

