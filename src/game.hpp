#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"

struct Coups{ 
  Box case;
  std::string mot;
  bool direction;
}

class Game{

    public:
        Board board;
        Player player;
        Lexicon lexicon;

        Game();
        ~Game();
        void liste_coups(std::string hand, std::vector<std::string>& tab);

};