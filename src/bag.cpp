#include <vector>

#include "bag.hpp"
#include "tile.hpp"

const int ALPHA = 26;

Bag::Bag() {
    initialize();
}

void Bag::initialize(){
    Tile tmp;
    char character = 'A';
    for(int i=0;i<ALPHA;i++){
        switch (i){
            case 0: tmp = Tile(character+i, 9); break;
            case 1: tmp = Tile(character+i, 2); break;
            case 2: tmp = Tile(character+i, 2); break;
            case 3: tmp = Tile(character+i, 3); break;
            case 4: tmp = Tile(character+i, 15); break;
            case 5: tmp = Tile(character+i, 2); break;
            case 6: tmp = Tile(character+i, 2); break;
            case 7: tmp = Tile(character+i, 2); break;
            case 8: tmp = Tile(character+i, 8); break;
            case 9: tmp = Tile(character+i, 1); break;
            case 10: tmp = Tile(character+i, 1); break;
            case 11: tmp = Tile(character+i, 5); break;
            case 12: tmp = Tile(character+i, 3); break;
            case 13: tmp = Tile(character+i, 6); break;
            case 14: tmp = Tile(character+i, 6); break;
            case 15: tmp = Tile(character+i, 2); break;
            case 16: tmp = Tile(character+i, 3); break;
            case 17: tmp = Tile(character+i, 6); break;
            case 18: tmp = Tile(character+i, 6); break;
            case 19: tmp = Tile(character+i, 6); break;
            case 20: tmp = Tile(character+i, 6); break;
            case 21: tmp = Tile(character+i, 2); break;
            case 22: tmp = Tile(character+i, 1); break;
            case 23: tmp = Tile(character+i, 1); break;
            case 24: tmp = Tile(character+i, 1); break;
            case 25: tmp = Tile(character+i, 1); break;
        }
        tiles.push_back(tmp);
    }
}

Tile Bag::getTile(unsigned int index) const{

    if(index >= 0 && index < ALPHA)
        return tiles.at(index);
    else
        return tiles.at(0);
}

Tile Bag::getTile(char letter) const{

    int indice = letter - 'A';

    if(indice >= 0 && indice < ALPHA)
        return tiles.at(letter);
    else
        return tiles.at(0);
}

bool Bag::decrementTile(char letter){
    int indice = letter - 'A';
    if(tiles.at(indice).getNumber() > 0){
        tiles.at(indice).decrementNumber();
        return true;
    }
    else{
        return false;
    }
}

void Bag::display() const{
    for(int i = 0; i < ALPHA; i++){
        std::cout << tiles.at(i).getLetter() << " : il reste " << tiles.at(i).getNumber() << " tiles, points : " << tiles.at(i).getPoints(tiles.at(i).getLetter()) << std::endl; 
    }
}

Bag::~Bag() { 
    tiles.clear();
}