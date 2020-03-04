#pragma once

#include <vector>

#include "bag.hpp"

class Player{

    public:
        Player();
        ~Player();
        void displayCurrentTiles();
        void replaceTile(char letter);
        char getPlayerTile(unsigned int position) const;

    private:
        std::vector<char> currentTiles;
        Bag bag;
        bool addTile(); //returns false if there are no more tiles in bag

};