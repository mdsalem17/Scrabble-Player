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
  std::stringstream ss ;
  Game game;

  game.board.placeWord(ss, 1, 0, 0, "TEST");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 1, 2, "FIN");
  game.board.load(ss) ;
  
  game.board.placeWord(ss, 1, 6, 7, "SEULE");
  game.board.load(ss) ;

  game.board.placeWord(ss, 0, 7, 7, "EST");
  game.board.load(ss) ;
  
  //game.board.placeWord(ss, 1, 7, 6, "GLU");
//  game.board.load(ss) ;

  std::cout << game.board << std::endl;

  //std::cout << game.board << std::endl;
  std::stack <State> moves;

  //add player.hand
  game.moves_list("TANUELG", tab_coups1, moves);

  for (unsigned int i = 0; i < tab_coups1.size(); i++) {
		std::cout << tab_coups1.at(i).mot <<" "<<std::endl;
	}

  /*
  for (unsigned int i = 0; i < tab_coups2.size(); i++) {
		std::cout << tab_coups2.at(i).mot <<" "<<std::endl;
	}*/

/*
  if(game.verify_crosswords(0, false)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
  
  if(game.verify_crosswords(20, false)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
  
  if(game.verify_crosswords(30, false)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
  
  if(game.verify_crosswords(112, false)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;  

  if(game.verify_crosswords(112, true)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
  
  if(game.verify_crosswords(0, true)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
  
  if(game.verify_crosswords(20, true)){
    std::cout <<" le crossword existe "<<std::endl;
  } else std::cout <<" le crossword n'existe pas "<<std::endl;
*/

  std::cout << tab_coups1.size() <<" "<<std::endl;

//  std::cout << moves.size() <<" "<<std::endl;

  std::cout << game.board << std::endl;
  

  std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl
            << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl
            << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

  std::vector<Coups> tab1;
  Game g;


  g.board.placeWord(ss, 1, 0, 2, "BLATTE");
  g.board.load(ss) ;

  g.board.placeWord(ss, 0, 3, 0, "BATEAUX");
  g.board.load(ss) ;
  
  g.board.placeWord(ss, 1, 6, 7, "SEULE");
  g.board.load(ss) ;

  g.board.placeWord(ss, 0, 7, 7, "EST");
  g.board.load(ss) ;

  std::cout << g.board << std::endl;


  g.moves_list("LSCE", tab1, moves);

  for (unsigned int i = 0; i < tab1.size(); i++) {
		std::cout << tab1.at(i).mot <<" "<<std::endl;
	}
  std::cout << tab1.size() <<" "<<std::endl;

}
