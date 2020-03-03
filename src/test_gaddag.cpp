#include <sstream>
#include <string>
#include <vector>

#include "lexicon.hpp"
#include "bag.hpp"
#include "player.hpp"

int main() {
  Lexicon l2;
  l2.downloadLexicon();
  std::cout<<"the size of the lexicon is "<<l2.size()<<std::endl;

  std::vector<std::string> array2 = {"ABAISSA", "ABAISSEUR", "ABORNERAIENT", "VAMPERIONS", "ART", "AMI", "URBANITE", "RAPETISSAIS", "ET", "RANGERONS", "LNKBJK HIEGB", "GERHAJ", "HERHAERHAE"};
  for(std::string word : array2) {
    if(l2.contains(word)) std::cout<<word<<" found"<<std::endl;
    else std::cout<<word<<" not found"<<std::endl;
  }
  Lexicon l;
  /**
  std::pair<std::string, std::string> p = splitString("LaFrogue", 3);
  std::cout<<std::endl<<"spliting into two words"<<std::endl;
  std::cout<<p.first<<std::endl;
  std::cout<<p.second<<std::endl;

  std::string word = "BATEAU";
  std::cout<<std::endl<<"testing addPlus function with word: "<<word<<std::endl;

  std::vector<std::string> tab;
  l.addPlus(word, tab);
  std::cout<<"length of tab :"<<tab.size()<<std::endl;
  printArray(tab);
  std::vector<std::string> t = { "123", "314", "456"};
  printArray(t);


  std::cout<<std::endl<<"testing found function"<<std::endl;
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
**/


  //Bag bag;
  //bag.display();

  Player player;
  std::cout << "current tiles "; player.displayCurrentTiles();
  std::cout << "remaining tiles " << player.getTotalTilesNb() << std::endl;
  
  player.removeTile('A');
  std::cout << "current tiles "; player.displayCurrentTiles();

  return 0 ;
}
