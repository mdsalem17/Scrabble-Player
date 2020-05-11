#pragma once

#include "include.hpp"
#include "board.hpp"
#include "player.hpp"
#include "lexicon.hpp"
#include <bits/stdc++.h> 
#include <ctype.h>

struct Coups{

    unsigned int spot;
    std::string mot;
    bool orientation;
    unsigned int score;

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
};

class Game{

    public:
        Game();
        ~Game();

        // "find_first_move" renvoie le meilleur coup possible initialement placé
        // à partir de la main du joueur
        Coups find_first_move(std::string hand);

        // "find_best_move" renvoie le meilleur coup possible à jouer à partir de la
        // configuration courrente et la main du joueur
        Coups find_best_move(std::string hand);

        // "adapt_word" modifie la case de depart et le mot pour permettre de placer
        // le mot sans le plus bien structuré à la bonne place  
        void adapt_word(unsigned int& case_depart, bool orientation, std::string& mot);

        Board board;
        Player player;
        Lexicon lexicon;
        unsigned int score;

    private:
        // "compare_moves" renvoie le meilleur coup parmi le nouveau et le meilleur
        // coup courant
        Coups compare_moves(Coups coup, Coups meilleurCoup);
        
        // "verify_crosswords" renvoie true s'il le mot créé à la case case_curr
        // selon l'orientation en utilisant le caractère c est bien valide
        bool verify_crosswords(unsigned int case_curr, bool orientation, char c = ' ');
        
        // "get_crosswords" renvoie la liste des mots croisés créés si on place
        // le mot word est placé sur le plateau à partir de la case case_curr
        // suivant l'orientation 
        std::vector<std::pair<unsigned int, std::string>> get_crosswords(unsigned int case_depart, std::string word, bool orientation);
        
        // "word_score" renvoie le score d'un mot placé à partir de la case case_curr
        // selon l'orientation 
        unsigned int word_score(unsigned int case_depart, std::string word, bool orientation);
        
        // "play_score" permet de calculer le score total de tous les mots créés du coup
        // Elle s'appuie "word_score"
        unsigned int play_score(unsigned int case_depart, std::string word, bool orientation, bool empty);
        
        // "moves_list_rec" récursive sur le noeud du lexicon. Elle renvoie les coups
        // possible à partir d'une case_curr, d'une orientation case et les lettres
        // restantes dans la main du joueur.
        void moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
                    std::string& mot, bool orientation, bool plus, Coups& meilleurCoup);
        
        // "moves_list" renvoie le meilleur coup possible à partir d'une case_depart,
        //  en fonctionnant de l'orientation et la main du joueur.
        // Elle s'appuie sur moves_list_rec.
        Coups moves_list(std::string hand, unsigned int case_depart, bool orientation);

        /// "valid_neighbour" permet de savoir si une case vide est voisine d'une case
        //  occupée 
        bool valid_neighbour(unsigned int case_curr );
    
};