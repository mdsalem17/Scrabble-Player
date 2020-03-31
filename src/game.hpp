#pragma once

#include "include.hpp"
#include "board.hpp"
#include "box.hpp"
#include "player.hpp"
#include "lexicon.hpp"

struct Coups{

    Coups(Box _box, std::string _mot, bool _orient){
        box = Box(_box);
        mot = _mot;
        orientation = _orient;
    }

    Box box;
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