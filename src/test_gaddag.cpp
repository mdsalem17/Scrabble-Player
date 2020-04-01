#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "game.hpp"

int main() {
  Game game;

  std::cout<<"the lexicon length is "<<game.lexicon.length<<std::endl;
  /**
   *  EELELUAG AGELEELU LEUGLEAE ALUELGEE ELELAEGU
  **/
  std::string hand = "ALUELGEE"; //LL GUA EEE

  std::string test = "ALLEGUEE"; //ALLEGUEE

  std::cout<<" test before removing duplicates = "<<test<<std::endl;
  remove_duplicate(test);
  std::cout<<" test after removing duplicates = "<<test<<std::endl;
  
    
  //appel game.liste_coups()


  return 0 ;
}