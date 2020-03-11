#pragma once

class Bag {
    public:
        Bag();
        ~Bag();

        char generateLetter();
        void displayBag();
        unsigned int getCharPoints(char _letter) const;
        unsigned int getNbLetters() const;

    private:
        char *tabLetters;
        unsigned int nbLetters;
        char tabNombreLetters;

        void initialize();
};