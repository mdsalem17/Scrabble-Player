#include <iostream>

#include "bag.hpp"

const int ALPHA = 26;
const int TILES = 102;

Bag::Bag() {
    tabLetters = new char[TILES];
    nbLetters = TILES;
    initialize();
}

//fonction qui renvoie les points de la lettre passee en parametre
unsigned int Bag::get_character_points(char _letter) const{
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
        case 'Q': points = 8; break;
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

void Bag::initialize(){

    unsigned int tabNbLetters[] = {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 3, 6, 6, 6, 6, 2, 1, 1, 1, 1};
    unsigned int start = 0;
    unsigned int end = 0;

    for(unsigned int i =0; i< ALPHA; i++){
        end += tabNbLetters[i];
        for(unsigned int j = start; j < end; j++){
            tabLetters[j] = 'A'+i;
        }
        start = end;
    }
}

void Bag::display_bag(){
    std::cout << " [ ";
    for(unsigned int i = 0; i < TILES; i++){
        std::cout << tabLetters[i] << ", "; 
    }
    std::cout << "] \n";
}

char Bag::generate_letter(){

    int random = rand() % nbLetters;
    char result = tabLetters[random];
    tabLetters[random] = tabLetters[nbLetters-1];
    nbLetters--;
    return result;
}

unsigned int Bag::get_nbLetters() const{
    return nbLetters;
}

Bag::~Bag() { 
    delete []tabLetters;
}