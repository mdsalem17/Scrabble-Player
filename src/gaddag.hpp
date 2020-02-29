#pragma once

#include "node.hpp"
#include <iostream>
#include <string>
#include <vector>

/** "src/test_board.cpp",  **/



/* The GADDAG data structure called for lexicon storage */
class Gaddag  {
  private:
    Node* root;
  
  public:
  //default initialization, charging the lexicon from the file
  Gaddag(std::vector<std::string> lexicon);

  //Gaddag(std::string file = "./data/dico.txt");

  void loadFromArray(std::vector<std::string> lexicon);

  void display() const;
  
} ;
