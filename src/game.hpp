#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"
#include <bits/stdc++.h> 
#include <ctype.h>

struct Coups{

    Coups(unsigned int _spot, std::string _mot, bool _orient, unsigned int _score){
        spot = _spot;
        mot = _mot;
        orientation = _orient;
        score = _score;
    }

    Coups& operator=(Coups c){
        spot = c.spot;
        mot = c.mot;
        orientation = c.orientation;
        score = c.score;
        return *this;
    }

    unsigned int spot;
    std::string mot;
    bool orientation;
    unsigned int score;
};

class Game{

    public:
        Board board;
        Player player;
        Lexicon lexicon;

        unsigned int score;

        Game();
        ~Game();
        Coups trouver_meilleur_coups(std::string hand);
        Coups moves_list(std::string hand, unsigned int case_depart, bool orientation);
        std::vector<std::pair<unsigned int, std::string>> get_crosswords(unsigned int case_depart, std::string word, bool orientation);
        unsigned int word_score(unsigned int case_depart, std::string word, bool orientation);
        unsigned int play_score(unsigned int case_depart, std::string word, bool orientation, bool empty);
        void adapt_word(unsigned int& case_depart, bool orientation, std::string& mot);

    private:
        void moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
                    std::string& mot, bool orientation, bool plus, Coups& meilleurCoup);    
        bool verify_crosswords(unsigned int case_curr, bool orientation, char c = ' ');    
        
    public:    
        bool check_word_not_on_board(unsigned int case_depart, bool orientation, std::string mot);


};