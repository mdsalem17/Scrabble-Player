#include <algorithm>

#include "player.hpp"

const int ALPHA = 26;

Player::Player(){
    //add 7 tiles in vector currentTiles
    for(unsigned int i = 0; i < 7; i++){
        addTile();
    }
}

void Player::displayCurrentTiles(){
    for(unsigned int i = 0; i < currentTiles.size(); i++){
        if(i == currentTiles.size()-1)
            std::cout << currentTiles.at(i);
        else
            std::cout << currentTiles.at(i) << ", ";
    }
    std::cout << "\n";
}

char Player::getPlayerTile(unsigned int position) const{
    return currentTiles.at(position);
}

bool Player::addTile(){
    if(bag.getNbTiles() > 0){
        unsigned int rand;
        char letter;
        do{
            rand = (std::rand() % ALPHA) + 'A';
            letter = rand;
            std::cout << "degub msg: random generated " << rand << " in char : " << letter << std::endl;
        }while(bag.getTile(letter).getNumber() == 0);

        currentTiles.push_back(letter);
        bag.decrementTile(letter);
        return true;
    }
    return false; //no tiles left.
}

void Player::replaceTile(char letter){

    //remove the tile (first occurence)
    std::vector<char>::iterator index = std::find(currentTiles.begin(), currentTiles.end(), letter);
    if (index != currentTiles.end()) // == myVector.end() means the element was not found
        currentTiles.erase(index);

    //replace removed tile (if possible)
    addTile();
}

Player::~Player(){

}