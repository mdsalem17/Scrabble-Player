#pragma once

#include "bag.hpp"

class Player{

    public:
        Bag bag;

        Player();
        ~Player();
        unsigned int getNbHandLetters();
        void setNbHandLetters(unsigned int nb_letters);
        bool replaceLetters(std::string word);
        std::string handToString();

    private:
        unsigned int nbHandLetters;
        unsigned int hand[26];

};