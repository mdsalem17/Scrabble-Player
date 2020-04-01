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
  
  std::vector<Coups> tab_coups1, tab_coups2;
  
  game.liste_coups("NALUELGE" , tab_coups1, tab_coups2);

  for (unsigned int i = 0; i < tab_coups1.size(); i++) {
		std::cout << tab_coups1.at(i).mot <<" "<<std::endl;
	}
  for (unsigned int i = 0; i < tab_coups2.size(); i++) {
		std::cout << tab_coups2.at(i).mot <<" "<<std::endl;
	}

  std::cout << tab_coups1.size() <<" "<<std::endl;
	std::cout << tab_coups2.size() <<" "<<std::endl;


  return 0 ;
}