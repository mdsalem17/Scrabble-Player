#include <algorithm>
#include <iostream>

#include "player.hpp"

const int ALPHA = 26;

Player::Player(){

    nbHandLetters = 7;

    for(unsigned int i = 0; i < ALPHA; i++){
        hand[i] = 0;
    }
    
    for(unsigned int i = 0; i < nbHandLetters; i++){
        char letter = bag.generateLetter();
        hand[letter-'A']++;
    }
}

std::string Player::handToString(){
    
    std::string word = "";
    char letter;

    for(unsigned int i = 0; i < ALPHA; i++){
        if(hand[i] > 0){
            for(unsigned int k = 0; k < hand[i]; k++){
                letter = 'A' + i;
                word += letter;
            }  
        }
    }
    return word;
}

bool Player::replaceLetters(std::string word){

    if(word.size() > 0){
        for(unsigned int i = 0; i < word.size(); i++){
        
            if(bag.getNbLetters() > 0){
                hand[ word[i] - 'A' ]--;
                char letter = bag.generateLetter();
                hand[ letter - 'A']++;
            }else if(bag.getNbLetters() < 7 && nbHandLetters > 0){
                hand[ word[i] - 'A' ]--;
                nbHandLetters--;
            }else{
                return false;
            }

        }
    }

    if(nbHandLetters > 0)
        return true;
    else
        return false;
}

unsigned int Player::getNbHandLetters(){
    return nbHandLetters;
}

void Player::setNbHandLetters(unsigned int nb_letters){
    nbHandLetters = nb_letters;
}

Player::~Player(){

}