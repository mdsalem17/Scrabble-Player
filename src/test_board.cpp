#include "game.hpp"

#include <iostream>
#include <sstream>

int main() {

  /*Board b;
  std::stringstream ss ;

  b.placeWord(ss, 1, 0, 0, "TEST");
  b.load(ss) ;

  b.placeWord(ss, 0, 1, 2, "FIN");
  b.load(ss) ;

  std::cout << b << std::endl ;*/

  std::vector<Coups> tab_coups;
  std::stringstream ss ;
  Game game;

  game.board.placeWord(ss, 1, 0, 0, "TEST");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 1, 2, "FIN");
  game.board.load(ss) ;

  std::cout << game.board << std::endl;

  //add player.hand
  game.liste_coups("ALUELGEN" , tab_coups);

  for (unsigned int i = 0; i < tab_coups.size(); i++) {
		std::cout << tab_coups.at(i).mot <<" "<<std::endl;
	}

  std::cout << game.board << std::endl;

}
