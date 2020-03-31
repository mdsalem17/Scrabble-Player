#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"

struct Coups{

    Coups(Spot _spot, std::string _mot, bool _orient){
        spot.letter = _spot.letter;
        spot.bonus = _spot.bonus;
        mot = _mot;
        orientation = _orient;
    }

    Spot spot;
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
        void liste_coups(std::string hand, std::vector<Coups>& tab);

};