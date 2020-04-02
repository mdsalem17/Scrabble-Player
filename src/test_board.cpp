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

  std::vector<Coups> tab_coups1;
  std::vector<Coups> tab_coups2;
  std::stringstream ss ;
  Game game;

  game.board.placeWord(ss, 1, 0, 0, "TEST");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 1, 2, "FIN");
  game.board.load(ss) ;
  
  game.board.placeWord(ss, 0, 7, 7, "E");
  game.board.load(ss) ;

  //std::cout << game.board << std::endl;
  std::stack <State> moves;

  //add player.hand
  game.moves_list("ANUELGE", tab_coups1, moves);

  for (unsigned int i = 0; i < tab_coups1.size(); i++) {
		std::cout << tab_coups1.at(i).mot <<" "<<std::endl;
	}/*
  for (unsigned int i = 0; i < tab_coups2.size(); i++) {
		std::cout << tab_coups2.at(i).mot <<" "<<std::endl;
	}*/

  std::cout << tab_coups1.size() <<" "<<std::endl;
	//std::cout << tab_coups2.size() <<" "<<std::endl;

  std::cout << moves.size() <<" "<<std::endl;

  std::cout << game.board << std::endl;
  //std::cout <<" board size "<< sizeof(game.board.spots)/sizeof(game.board.spots[0]) << std::endl;

}
