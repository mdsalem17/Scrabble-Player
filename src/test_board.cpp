#include "board.hpp"

#include <iostream>
#include <sstream>

int main() {

  //std::cout << b << std::endl ;
  
  /*ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "....PROJET....." << std::endl ;
  ss << ".......O......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".......E......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".....SCRABBLE.." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;*/

  Board b;
  std::stringstream ss ;

  b.placeWord(ss, 1, 0, 0, "test");
  b.load(ss) ;

  b.placeWord(ss, 0, 1, 2, "function");
  b.load(ss) ;

  std::cout << b << std::endl ;

  return 0 ;
}
