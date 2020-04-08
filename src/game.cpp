#include "game.hpp"


Game::Game(){
    lexicon.downloadLexicon();
    std::cout << "lexicon downloaded" << std::endl;
}

static bool moves_available(unsigned int case_curr, bool orientation, bool plus){
  
  if(case_curr >= 225)
    return false;

  if(orientation){
    //vertical
    if(plus){
      if( case_curr >= 210 && case_curr<=224)
        return false;
    } else{
      if( case_curr<= 14 )
        return false;
    }
  } else{
    //horizontal
    if(plus){
      if( case_curr %15 == 14 )
        return false;
    } 
    else{
      //on se deplace horizontalement
      if( case_curr%15 == 0 )
        return false;
    }
  }
  
  return true;
}

static void deplacement(bool orientation, bool plus, unsigned int& case_curr){
  if(!plus){
    if(orientation){
      case_curr-= 15;
    } else{
      case_curr--;
    }
  } else{
    if(orientation){
      case_curr+= 15;
    } else{
      case_curr++;
    }
  }
}

void Game::moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
          std::string& mot, bool orientation, bool plus, std::vector<Coups>& tab, std::stack <State>& moves){

	if(!moves.empty()) moves.pop();

	char pcurr;
  Node* curr = n;
  char p = '+';

  if(board.spots[case_curr].letter != 0){

		pcurr = board.spots[case_curr].letter;
		if( curr->suffixes.count(pcurr) > 0 ) {
			curr = curr->suffixes.at(pcurr);
			mot += pcurr;
      std::cout<<"-------------------- ajout pcurr (dans if case non vide) "<<mot<<std::endl;
      if(curr->isWord) {
          Coups c(case_depart, mot, orientation);
          tab.push_back(c);
      }
      
      deplacement(orientation, plus, case_curr);
      std::cout<<"la case courante = "<<case_curr<<std::endl;
      std::cout<<"la lettre courante = "<<board.spots[case_curr].letter<<std::endl;
      if(moves_available(case_curr, orientation, plus)){
        State s(hand, curr, case_curr);
        moves.push(s);

        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
      }  else{
        pcurr = board.spots[case_curr].letter;
        if( curr->suffixes.count(pcurr) > 0 ) {
          curr = curr->suffixes.at(pcurr);
     			mot += pcurr;
          std::cout<<"la lettre courante = pcurr ="<<pcurr<<std::endl;
          if( curr->suffixes.count(p) > 0 ) {
            curr = curr->suffixes.at(p);
            mot += p;
            std::cout<<"mot => "<<mot<<std::endl;
            plus = true;
            case_curr = case_depart;
            
            deplacement(orientation, plus, case_curr);
            State s(hand, curr, case_curr); 
            moves.push(s);

            moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
          }
        }
      }
    }
  }  else{
		if( curr->suffixes.count(p) > 0 ) {
			curr = curr->suffixes.at(p);
      mot += p;
      std::cout<<"mot => "<<mot<<std::endl;
			plus = true;
			case_curr = case_depart;
			
      deplacement(orientation, plus, case_curr);
      State s(hand, curr, case_curr); 
      moves.push(s);

      moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
    } else {
      std::string _mot = mot;
      std::string h_iterator = hand;
      unsigned int _case_curr = case_curr;
      remove_duplicate(h_iterator);
      for(unsigned int i =0; i<h_iterator.size(); i++){
        Node* curr = n;
        char pcurr = h_iterator[i];
        std::string h = hand;
        remove(pcurr, h);

        if( curr->suffixes.count(pcurr) > 0 ) {
          curr = curr->suffixes.at(pcurr);
          std::cout<<"in else pcurr "<< pcurr <<std::endl;          
          mot += pcurr;

          if(curr->isWord) {
            Coups c(case_depart, mot, orientation);
            tab.push_back(c);
          }
          
          deplacement(orientation, plus, case_curr);
          if(moves_available(case_curr, orientation, plus)){
            State s(hand, curr, case_curr); 
            moves.push(s);
              
            moves_list_rec(curr, h, case_depart, _case_curr, mot, orientation, plus, tab, moves);
          }
        }
        mot = _mot;
        _case_curr = case_curr;
      }
    }
  }
}

bool Game::verify_crosswords(unsigned int case_curr, bool orientation){
  std::string word = "";
  unsigned int _case = case_curr;

  if(board.spots[_case].letter != 0){
    word +=board.spots[_case].letter;
  }

  while( board.spots[_case].letter != 0  && moves_available(_case, !orientation, false) ){
    deplacement(!orientation, false, _case);
    word +=board.spots[_case].letter;
    std::cout<<" crossword --- la case courante ="<<_case<<std::endl;
  }

  _case = case_curr;
  if( word != ""){
    word += "+";
  }


  while( board.spots[_case].letter != 0 && moves_available(_case, !orientation, true)){
    deplacement(!orientation, true, _case);
    word += board.spots[_case].letter;
  }

  std::cout<<"le mot du crossword ="<<word<<"la frogue "<<std::endl;

  return lexicon.contains(word);
}

void Game::moves_list(std::string hand, std::vector<Coups>& tab1, std::stack <State>& moves){

  unsigned int case_depart = 19;
	bool orientation;
	bool plus = false;
  orientation = false;
	unsigned int case_curr = case_depart;
  std::string mot = "";
  moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, tab1, moves);

}

Game::~Game(){

}