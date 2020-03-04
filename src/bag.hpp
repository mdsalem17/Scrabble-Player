#pragma once

#include <vector>

#include "include.hpp"
#include "tile.hpp"

class Bag {
    public:
        Bag();
        ~Bag();

        void display() const;
        void initialize();
        unsigned int getNbTiles() const;
        Tile getTile(unsigned int index) const;
        Tile getTile(char letter) const;
        bool decrementTile(char letter);

    private:
        std::vector<Tile> tiles;
        unsigned int nbTiles;
};