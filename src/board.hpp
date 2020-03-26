#pragma once

#include "spot.hpp"
#include "box.hpp"

#include <iostream>
#include <vector>


/* Scrabble board */
struct Board {
  //default initialization of a scrabble board
  Board() ;

  //i/o to files
  void save(std::ostream& out) ;
  void load(std::istream& in) ;

  //access to the spots by coordinates
  Spot operator()(unsigned char l, unsigned char c) const ;
  Spot& operator()(unsigned char l, unsigned char c) ;

  /**
   * ss => stringstream used to print the board later
   * orientation => 1 is vertical, 0 is horizontal
   * init_i, init_j => statring box 
   * word => string containting the word to be placed on the board
   * */
  void placeWord(std::stringstream & ss, bool orientation, unsigned int init_i, unsigned int init_j, std::string word);

  //spots are public, and can therefore also be accessed by index
  Spot spots[225] ;

  //boxes containt all the board letters by indexes (also used to place letters on the board)
  Box boxes[15][15];

} ;

//board display on the console
std::ostream& operator<<(std::ostream& out, const Board& b) ;
