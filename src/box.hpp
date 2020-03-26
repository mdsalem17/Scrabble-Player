#pragma once

class Box {

  public:
    Box();
    Box(unsigned int _i, unsigned int _j);
    char getBoxLetter();
    void setBoxLetter(char _letter);
    bool isEmpty();
    unsigned int p;


  private:
    unsigned int i;
    unsigned int j;    
    char letter;

};