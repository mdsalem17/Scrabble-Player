#pragma once

class Tile {
    private:
        char letter;
        unsigned int point;
    public:
        Tile();
        Tile(char _c, unsigned int _point);
        unsigned int getPoint() const;
        char getLetter() const;
        ~Tile();
};