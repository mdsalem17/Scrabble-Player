#pragma once
#include "include.hpp"
#include "tile.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class Bag {
    public:
        Bag() {
            root = nullptr;
        }

        ~Bag() { 
            delete root;
        }

        void display() const;
        void initialize();


    private:
        std::vector<Tile> array;
};

/**
void wordlist::valueVector(void){
    int x;
    for(int i=0;i<ALPHA;i++){
        switch (i){
            case 0: x=1; break;
            case 1: x=3; break;
            case 2: x=3; break;
            case 3: x=2; break;
            case 4: x=1; break;
            case 5: x=4; break;
            case 6: x=2; break;
            case 7: x=4; break;
            case 8: x=1; break;
            case 9: x=8; break;
            case 10: x=5; break;
            case 11: x=1; break;
            case 12: x=3; break;
            case 13: x=1; break;
            case 14: x=1; break;
            case 15: x=3; break;
            case 16: x=10; break;
            case 17: x=1; break;
            case 18: x=1; break;
            case 19: x=1; break;
            case 20: x=1; break;
            case 21: x=4; break;
            case 22: x=4; break;
            case 23: x=8; break;
            case 24: x=4; break;
            case 25: x=10; break;
        }
        values.push_back(x);
    }
} 
 ** /