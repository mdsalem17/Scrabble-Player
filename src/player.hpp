#pragma once

#include <vector>

#include "bag.hpp"

class Player{

    public:
        Player();
        ~Player();
        void displayCurrentTiles();
        unsigned int getTotalTilesNb();
        void removeTile(char letter);

    private:
        std::vector<char> currentTiles;
        Bag bag;
        bool addTile(); //returns false if there are no more tiles in bag

};