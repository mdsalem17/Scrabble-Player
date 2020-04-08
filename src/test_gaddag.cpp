#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "game.hpp"

int main() {
  Game game;

  std::cout<<"the lexicon length is "<<game.lexicon.length<<std::endl;

  std::string hand = "ALUELGEE";

  std::vector<Coups> tab_coups1, tab_coups2;
  

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