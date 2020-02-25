#include "lexicon.hpp"
#include <vector>
#include <iostream>
#include <sstream>

int main() {
  Lexicon l;
  std::vector<std::string> array = {"A", "LE", "EN", "ARC", "ART", "AMI", "LES", "LA", "ET", "ERG"};
  for(std::string word : array) l.add(word);

  for(std::string word : array) {
    if(l.contains(word)) std::cout<<word<<" found"<<std::endl;
    else std::cout<<word<<" not found"<<std::endl;
  }
  
  std::vector<std::string> TASSA = {"AMOUR", "LECHAGE", "ARC-EN-CIEL", "AMIGDALES", "LAPINE", "ETIC"};
  for(std::string word : TASSA) {
    if(l.contains(word)) std::cout<<word<<" found"<<std::endl;
    else std::cout<<word<<" not found"<<std::endl;
  }

  l.display();

  Lexicon l2;
  l2.loadFromFile();
  l2.display();

  return 0 ;
}
