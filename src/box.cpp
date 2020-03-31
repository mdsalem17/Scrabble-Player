#include "box.hpp"

Box::Box(){
  i = 0;
  j = 0;
  letter = '.';
}

Box::Box(unsigned int _i, unsigned int _j){
  i = _i;
  j = _j;
  letter = '.';
}

Box::Box(const Box &_box){
  i = _box.i;
  j = _box.j;
  letter = _box.letter;
}

char Box::getBoxLetter(){
  return letter;
}

void Box::setBoxLetter(char _letter){
    letter = _letter;
}

bool Box::isEmpty(){
    return letter == '.';
}