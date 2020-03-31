#include "game.hpp"
#include "include.hpp"
//#include "box.hpp"
/**

**/
Game::Game(){
    lexicon.downloadLexicon();
    std::cout << "lexicon downloaded" << std::endl;
}

/**
 * static void liste_coups(Node* n, std::string hand, Box case_depart, Box case_curr, std::string& mot,
      bool direction, bool plus, std::vector<Coups>& tab){
*/
static void liste_coups_rec(Node* n, std::string hand, Box case_depart, Box case_curr, std::string& mot,
      bool direction, bool plus, std::vector<Coups>& tab){
//static void liste_coups_rec(Node* n, std::string hand, std::string& mot, bool plus, std::vector<std::string>& tab){

  std::string _mot = mot;
  std::string h_iterator = hand;
  remove_duplicate(h_iterator);
  for(unsigned int i =0; i<h_iterator.size(); i++){
    // if the current letter node exists
    Node* curr = n;
    std::string h = hand;
    if(case_curr.isEmpty()){
      // la case courrente est vide
      char pcurr = h_iterator[i];
      remove(pcurr, h);
      if( curr->suffixes.count(pcurr) > 0) {
        curr = curr->suffixes.at(pcurr);
        mot += pcurr;
        if(curr->isWord) {
          Coups c(case_depart,mot,direction);
          tab.push_back(c);
        }
        std::cout<<"la main est "<<h<<std::endl;
        Coups c(case_depart,mot,direction);
        liste_coups_rec(curr, h, case_depart, case_curr, mot, direction, plus, tab);
      }
    } else{ // la case concurrette n'est pas vide
      char pcurr = case_curr.getBoxLetter();
      std::cout<<"pcurr = "<<pcurr<<std::endl;
      if( curr->suffixes.count(pcurr) > 0) {
        curr = curr->suffixes.at(pcurr);
        mot += pcurr;
        if(curr->isWord) {
          std::cout<<"j'ai trouvé un mot qui est "<<mot<<std::endl;
          Coups c(case_depart,mot,direction);
          tab.push_back(c);
        }
          std::cout<<"le mot est "<<mot<<std::endl;
          std::cout<<"la main est "<<h<<std::endl;
          liste_coups_rec(curr, h, case_depart, case_curr, mot, direction, plus, tab);
        }
      }
    }
    mot = _mot;
}

void Game::liste_coups(std::string hand, std::vector<Coups>& tab){
  std::string mot = ""; 
  //bool plus = false;
  Box case_depart(1,1);
  Box case_curr;
  liste_coups_rec(lexicon.root, hand, case_depart, case_curr, mot, true, false, tab);

  //printArray(tab);
	for (unsigned int i = 0; i < tab.size(); i++) {
		std::cout << tab.at(i).mot <<" "<<std::endl;
	}


  std::cout<<"the tab length is "<<tab.size()<<std::endl;
}


/*
static void generate(Box position,  std::string& word, std::string rack, Node* arc){
  if(! position.isEmpty()){
    goOn(position, position.getBoxLetter, word, rack, n->suffixes.at(i)), arc);
  } else if(rack.size()>0){
    for(char letter: rack){
      if(alllowed(letter)){
        goOn(position, letter, word, remove(letter, rack), arc->suffixes.[i], arc);
      }
    }
  }
}


static void goOn(Box position, char letter, std::string word, std::string rack, Node* nArc,
                                                         Node* oArc, std::vector<Coups> tab){
  if ( positon.x <= 0 && position.y <= 0){
    word = letter + word;
    if(oArc->suffixes.count(letter) > 0){
      Coups c(position, mot, direction);
      tab.push_back(c);
    }

    if( nArc != nullptr){
      if((position.i--) >0 ){
        generate(position, word, rack, nArc);
        if(oArc->suffixes.count(letter) > 0 && (position.i++) <16){
          position.p = 1;
          generate(position, word, rack, nArc);
        }
      }
    }

  }
  else if (position.p > 0){
    word = word + letter;
    if(oArc->suffixes.count(letter) > 0){
      Coups c(position, mot, direction);
      tab.push_back(c);
    }
    if(nArc != nullptr && (position.i++) >0){
      generate(position, word, rack, nArc);
    }
  
  }

}

*/

Game::~Game(){

}