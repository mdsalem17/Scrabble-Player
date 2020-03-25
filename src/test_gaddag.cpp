#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "game.hpp"

int main() {
  Game game;

  std::cout<<"the lexicon length is "<<game.lexicon.length<<std::endl;
  
  std::string hand = "LLAEEUG"; //ALLEGUEE
  std::cout<<"the string after removing "<<hand<<std::endl;
  
  std::string mot = "";
  
  std::vector<std::string> tab;
  
  game.rechercheMot(game.lexicon.root, hand, mot, tab);

  //recherche(l.root, hand, tab);

  std::cout<<"the tab length is "<<tab.size()<<std::endl;
  printArray(tab);

  return 0 ;
}