#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"

class Game{

    public:
        Board board;
        Player player;
        Lexicon lexicon;

        Game();
        ~Game();
        void rechercheMot(Node* root, std::string hand, std::string mot, std::vector<std::string>& tab);
        void remove(char c, std::string& word);

};