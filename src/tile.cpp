#pragma once
#include "tile.h"


Tile::Tile(char _c, unsigned int _point){
    _c = c;
    _point = point;
}

Tile::unsigned int getPoint()const{
    return point;
}

Tile::char getLetter() const{
    return letter;
}

Tile::~Tile(){}

