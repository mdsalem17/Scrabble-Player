#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "lexicon.hpp"
#include "bag.hpp"
#include "player.hpp"

void remove(char c, std::string& word){
  std::string m = "";
  bool first = false;
  for(unsigned int i=0; i<word.size(); i++){
    if(first) m+= word[i];
    else if(word[i] == c) first = true;
    else m += word[i];
  }
  word = m;
}

void liste_coups(Node* n, std::string hand, std::string& mot, std::vector<std::string>& tab){
  for(unsigned int i =0; i<hand.size(); i++){
    // if the current letter node exists
    Node* curr = n;
    char pcurr = hand[0];
    std::string h = hand;
    std::cout<<"je rentre dans le for"<<std::endl;
    if( curr->suffixes.count(pcurr) > 0) {
      mot += pcurr;
      remove(pcurr, h);
      if(curr->isWord) {
        std::cout<<"j'ai trouvé un mot qui est "<<mot<<std::endl;
        tab.push_back(mot);
      }
      std::cout<<"le mot est "<<mot<<std::endl;
      std::cout<<"la main est "<<h<<std::endl;
      curr = curr->suffixes.at(pcurr);
      liste_coups(curr, h, mot, tab);
    }
    mot = "";
  }

}

int main() {
  Lexicon l;

  l.downloadLexicon();

  std::cout<<"the lexicon length is "<<l.length<<std::endl;
  
  std::string hand = "LALEEUG";
  std::cout<<"the string after removing "<<hand<<std::endl;
  
  std::string mot = "";
  
  std::vector<std::string> tab;
  
  liste_coups(l.root, hand, mot, tab);

  std::cout<<"the tab length is "<<tab.size()<<std::endl;
  printArray(tab);

  return 0 ;
}