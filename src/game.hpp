#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"

struct Coups{

    Coups(unsigned int _spot, std::string _mot, bool _orient){
        spot = _spot;
        mot = _mot;
        orientation = _orient;
    }

    unsigned int spot;
    std::string mot;
    bool orientation;
};

class Game{

    public:
        Board board;
        Player player;
        Lexicon lexicon;

        Game();
        ~Game();
        void liste_coups(std::string hand, std::vector<Coups>& tab1, std::vector<Coups>& tab2);

    private:
        void liste_coups_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr, std::string& mot,
                                        bool orientation, bool plus, std::vector<Coups>& tab);

};