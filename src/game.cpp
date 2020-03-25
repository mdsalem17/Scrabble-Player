#include "game.hpp"

Game::Game(){
    lexicon.downloadLexicon();
    std::cout << "lexicon downloaded" << std::endl;
}

void Game::remove(char c, std::string& word){
  std::string m = "";
  bool first = false;
  for(unsigned int i=0; i<word.size(); i++){
    if(first) m+= word[i];
    else if(word[i] == c) first = true;
    else m += word[i];
  }
  word = m;
}

void Game::rechercheMot(Node* root, std::string hand, std::string mot, std::vector<std::string>& tab){
  for(unsigned int i =0; i<hand.size(); i++){
    Node* curr = root;
    char pcurr = hand[i];
    std::string h = hand;
    
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
      rechercheMot(curr, h, mot, tab);
    }
    mot = "";
  }


    /* version not working
    char cstr[hand.size()];
	  strcpy(cstr, hand.c_str());

    for (auto& x: cstr) {
      if (curr->suffixes.count(x)>0){
        mot += pcurr;
        remove(pcurr, h);

        curr = curr->suffixes.at(pcurr);
        rechercheMot(curr, h, mot, tab);
      }
    }*/

    /* version 1
    if(curr->suffixes.count(pcurr) > 0) {

      mot += pcurr;
      remove(pcurr, h);

      curr = curr->suffixes.at(pcurr);
      rechercheMot(curr, h, mot, tab);
    }*/

  /*Node* curr = n;
  std::string h = hand;

  if(curr->isWord){
      tab.push_back(mot);
  }

  for(unsigned int i = 0; i < hand.length(); i++){
    char pcurr = hand[i];

    if(curr->suffixes.count(pcurr) > 0){
      curr = curr->suffixes.at(pcurr);
      rechercheMot(curr, h, mot+pcurr, tab);
    }

  }*/

}

/*void recherche(Node* n, std::string hand, std::vector<std::string>& tab){
  Node* pChild = n;
  std::string str = "";

  for(unsigned int i = 0; i < hand.length(); i++){
    if(pChild->suffixes.at(hand[i])){ //&& pChild->isWord 
      str = str+hand[i];
      rechercheMot(pChild->suffixes.at(hand[i]), hand, str, tab); 
      str = "";
    } 
  }
}*/

Game::~Game(){

}