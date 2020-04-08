#include "game.hpp"

#include <iostream>
#include <sstream>

int main() {

  /**
  * Board b;
  * std::stringstream ss ;
  *
  * b.placeWord(ss, 1, 0, 0, "TEST");
  * b.load(ss) ;
  *
  * b.placeWord(ss, 0, 1, 2, "FIN");
  * b.load(ss) ;
  *
  * std::cout << b << std::endl ;
  **/

  std::vector<Coups> tab_coups1;
  std::vector<Coups> tab_coups2;
  std::stringstream ss ;
  Game game;

  game.board.placeWord(ss, 1, 0, 0, "TEST");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 1, 1, "AFIN");
  game.board.load(ss) ;
  
  game.board.placeWord(ss, 1, 6, 7, "SEULE");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 7, 7, "EST");
  game.board.load(ss) ;

  //std::cout << game.board << std::endl;
  std::stack <State> moves;

  //add player.hand
  //game.moves_list("ANUELGE", tab_coups1, moves);

  for (unsigned int i = 0; i < tab_coups1.size(); i++) {
		std::cout << tab_coups1.at(i).mot <<" "<<std::endl;
	}

  /*
  for (unsigned int i = 0; i < tab_coups2.size(); i++) {
		std::cout << tab_coups2.at(i).mot <<" "<<std::endl;
	}*/

  std::cout << game.board << std::endl;

  if(game.verify_crosswords(0, false)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;

  std::cout << "SET+T" << std::endl;
  if(game.lexicon.contains("SET+T")){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;

  std::cout << tab_coups1.size() <<" "<<std::endl;

  std::cout << moves.size() <<" "<<std::endl;

  std::cout << game.board << std::endl;

}
