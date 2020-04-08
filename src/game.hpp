#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"
#include "include.hpp"
#include <bits/stdc++.h> 

struct State{
	std::string hand;
	Node* n;
	unsigned int case_curr;

    State(std::string _hand, Node* _n, unsigned int _case_curr){
        hand = _hand;
        n = _n;
        case_curr = _case_curr;
    }
};

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
        void moves_list(std::string hand, std::vector<Coups>& tab1, std::stack<State>& moves);

    private:
        void moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
          std::string& mot, bool orientation, bool plus, std::vector<Coups>& tab, std::stack <State>& moves);
     public:     
        bool verify_crosswords(unsigned int case_curr, bool orientation);


};