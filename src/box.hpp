#pragma once

class Box {

  public:
    Box();
    Box(unsigned int _i, unsigned int _j);
    Box(const Box &_box);
    char getBoxLetter();
    void setBoxLetter(char _letter);
    bool isEmpty();

  private:
    unsigned int i;
    unsigned int j;    
    char letter;

};