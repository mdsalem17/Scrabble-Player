#pragma once

#include "bag.hpp"

class Player{

    public:
        Bag bag;

        Player();
        ~Player();
        unsigned int getCurrentNbTiles();
        void displayCurrentTiles();
        void replaceTile(int pos);

    private:
        unsigned int nbCurrentTiles;
        char *currentTiles;

};