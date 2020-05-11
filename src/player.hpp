#pragma once

#include "bag.hpp"

class Player{

    public:
        Bag bag;

        Player();
        ~Player();

        // "getNbHandLetters" renvoie le nombre de lettres dans la main
        unsigned int get_nbHandLetters();

        // "setNbHandLetters" utilisée pour définir le nombre de lettres de la main
        void set_nbHandLetters(unsigned int nb_letters);

        // "replaceLetters" remplace les lettres utilisée pour construit le mot
        // sur le plateau
        bool replace_letters(std::string word);

        // "handToString" renvoie les lettres de la main sous forme d'une chaine
        // de caractères (string)
        std::string hand_to_string();

    private:
        unsigned int nbHandLetters;
        unsigned int hand[26];

};
