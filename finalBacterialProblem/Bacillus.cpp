#include "Bacillus.h"

void Bacillus::checkNearby(std::vector<std::vector<char>> area) {
    isDying = true;
    for (int i = getX() - 3; i <= getX() + 3; i++) {
        for (int j = getY() - 3; j <= getY() + 3; j++) {
            
            if (i < 0 || i >= area.size() || j < 0 || j >= area.size())
                continue;
            if (area[i][j] == 'C')
            {
                isDying = false;
            }
               
        }
    }
}

Bacillus::Bacillus(int X, int Y, int Nearby) {
    x = X;
    y = Y;
    nearby = Nearby;
    bacteriaName = 'B';
}

Bacterium* Bacillus::makeAChild(std::vector<std::vector<char>>& petriDish, std::list<Bacterium*>& bacteria) {

    std::vector<std::pair<int, int>> availableTiles;
    for (int i = getX() - nearby; i <= getX() + nearby; i++) {
        for (int j = getY() - nearby; j <= getY() + nearby; j++) {

            if (i < 0 || i >= petriDish.size() || j < 0 || j >= petriDish.size())
                continue;
            if (petriDish[i][j] == '*')
            {
                availableTiles.push_back({ i,j });
            }

        }
    }
    int size = availableTiles.size();
    if (size > 0) {
        srand(time(NULL));
        int x = rand() % size;
        petriDish[availableTiles[x].first][availableTiles[x].second] = bacteriaName;
            return(new Bacillus(availableTiles[x].first, availableTiles[x].second, nearby));
    }
}
