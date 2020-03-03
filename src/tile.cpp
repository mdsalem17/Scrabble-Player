#include "tile.hpp"

Tile::Tile(){
    letter = 'a';
    number = 1;
}

Tile::Tile(char _letter, unsigned int _nombre){
    letter = _letter;
    number = _nombre;
}

char Tile::getLetter() const{
    return letter;
}

unsigned int Tile::getNumber() const{
    return number;
}

void Tile::decrementNumber(){
    number--;
}

//fonction qui renvoie les points de la lettre passee par parametre
unsigned int Tile::getPoints(char _letter) const{
    unsigned int points = 0;
    switch (_letter){
        case 'A': points = 1; break;
        case 'B': points = 3; break;
        case 'C': points = 3; break;
        case 'D': points = 2; break;
        case 'E': points = 1; break;
        case 'F': points = 4; break;
        case 'G': points = 2; break;
        case 'H': points = 4; break;
        case 'I': points = 1; break;
        case 'J': points = 8; break;
        case 'K': points = 10; break;
        case 'L': points = 1; break;
        case 'M': points = 2; break;
        case 'N': points = 1; break;
        case 'O': points = 1; break;
        case 'P': points = 3; break;
        case 'Q': points = 2; break;
        case 'R': points = 1; break;
        case 'S': points = 1; break;
        case 'T': points = 1; break;
        case 'U': points = 1; break;
        case 'V': points = 4; break;
        case 'W': points = 10; break;
        case 'X': points = 10; break;
        case 'Y': points = 10; break;
        case 'Z': points = 10; break;
    }
    return points;
}

Tile::~Tile(){

}

