#include "box.hpp"

Box::Box(){
  i = 0;
  j = 0;
  letter = '.';
  p=0;
}

Box::Box(unsigned int _i, unsigned int _j){
  i = _i;
  j = _j;
  letter = '.';
  p=0;
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