#pragma once

class Bag {
    public:
        Bag();
        ~Bag();

        // "generateLetter" qui permet de piocher une letter du sac
        // en temps constant
        char generate_letter();
        
        // "displayBag" affiche le contenu du sac
        void display_bag();
        
        // "getCharPoints" renvoie le score d'une lettre passée en paramètre
        // utilisée pour calculer le score final d'un mot
        unsigned int get_character_points(char _letter) const;
        
        // "getNbLetters" renvoie le nombre de lettres restantes dans le sac
        unsigned int get_nbLetters() const;

    private:
        char *tabLetters;
        unsigned int nbLetters;
        char tabNombreLetters;

        // "initialize" initialise le sac avec les 102 lettres
        void initialize();
};
