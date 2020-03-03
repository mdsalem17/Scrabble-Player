#include <algorithm>

#include "player.hpp"

const int ALPHA = 26;

Player::Player(){
    //add 7 tiles in vector currentTiles
    currentTiles.push_back('A');
    bag.decrementTile('A');
    currentTiles.push_back('B');
    bag.decrementTile('B');
    currentTiles.push_back('C');
    bag.decrementTile('C');
    currentTiles.push_back('A');
    bag.decrementTile('A');
}

void Player::displayCurrentTiles(){
    for(unsigned int i = 0; i < currentTiles.size(); i++){
        std::cout << currentTiles.at(i) << ", ";
    }
    std::cout << "\n";
}

unsigned int Player::getTotalTilesNb(){
    unsigned int totalTiles = 0;
    for(unsigned int i = 0; i < ALPHA; i++){
        totalTiles += bag.getTile(i).getNumber();
    }
    return totalTiles;
}

bool Player::addTile(){
    //complete function
}

void Player::removeTile(char letter){

    //remove the tile (first occurence)
    std::vector<char>::iterator index = std::find(currentTiles.begin(), currentTiles.end(), letter);
    if (index != currentTiles.end()) // == myVector.end() means the element was not found
        currentTiles.erase(index);

    //replace removed tile (if possible)
    addTile();
}

Player::~Player(){

}