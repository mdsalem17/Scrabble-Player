#include <algorithm>
#include <iostream>

#include "player.hpp"

const int ALPHA = 26;

Player::Player(){

    nbCurrentTiles = 7;
    currentTiles = new char[nbCurrentTiles];
    
    for(unsigned int i = 0; i < nbCurrentTiles; i++){
        currentTiles[i] = bag.generateLetter();
    }
}

void Player::displayCurrentTiles(){
    for(unsigned int i = 0; i < nbCurrentTiles; i++){
        if(i == nbCurrentTiles-1)
            std::cout << currentTiles[i];
        else
            std::cout << currentTiles[i] << ", ";
    }
    std::cout << "\n";
}

void Player::replaceTile(int pos){
    currentTiles[pos] = bag.generateLetter();
}

unsigned int Player::getCurrentNbTiles(){
    return nbCurrentTiles;
}

Player::~Player(){
    delete []currentTiles;
}