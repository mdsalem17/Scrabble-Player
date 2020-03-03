#pragma once

class Tile {
    private:
        char letter;
        unsigned int number;
        unsigned int point;
    public:
        Tile();
        Tile(char _letter, unsigned int _nombre);
        char getLetter() const;
        unsigned int getNumber() const;
        void decrementNumber();
        unsigned int getPoints(char _letter) const;
        ~Tile();
};