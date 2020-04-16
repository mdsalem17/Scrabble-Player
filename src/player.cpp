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
    std::cout << "\n";
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

    for(unsigned int i = 0; i < word.length(); i++){
        
        if(bag.getNbLetters() > 0){
            hand[ word[i] - 'A' ]--;
            char letter = bag.generateLetter();
            hand[ letter - 'A']++;
        }else{
            return false;
        }

    }

    for(unsigned int i = 0; i < ALPHA; i++){
        char letters = 'A'+i;
        std::cout << letters << " "; 
    }
    std::cout << std::endl;
    for(unsigned int i = 0; i < ALPHA; i++){
        std::cout << hand[i] << " ";
    }
    std::cout << std::endl;

    return true;
}

unsigned int Player::getNbHandLetters(){
    return nbHandLetters;
}

Player::~Player(){

}