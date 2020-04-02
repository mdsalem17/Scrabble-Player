#include "game.hpp"


Game::Game(){
    lexicon.downloadLexicon();
    std::cout << "lexicon downloaded" << std::endl;
}

/**
 * static void liste_coups(Node* n, std::string hand, Spot case_depart, Spot case_curr, std::string& mot,
      bool orientation, bool plus, std::vector<Coups>& tab){
*/

void Game::liste_coups_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
                                    std::string& mot, bool orientation, bool plus, std::vector<Coups>& tab){

  if(case_curr<225 && case_depart<225){
    char pcurr;
    Node* curr;
    char p = '+';

    if(board.spots[case_curr].letter != 0){
      //std::cout<<"la case n'est pas vide "<<case_curr<<std::endl; 
      curr = n;
      //si la case n'est pas vide
      pcurr = board.spots[case_curr].letter;
      //std::cout<<"pcurr = box letter "<< pcurr <<std::endl;
      if( curr->suffixes.count(pcurr) > 0) {
        curr = curr->suffixes.at(pcurr);
        //std::cout<<"in if pcurr "<< pcurr <<std::endl;
        mot += pcurr;
        if(curr->isWord) {
          //std::cout<<"j'ai trouvé un mot qui est "<<mot<<std::endl;
          Coups c(case_depart, mot, orientation);
          tab.push_back(c);
        }

        if(orientation){
          case_curr += 15;
        } else{
          case_curr++;
        }

        liste_coups_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab);
      }

    } else if(board.spots[case_curr].letter == 0){
      //std::cout<<"la case est vide "<<case_curr<<std::endl; 
      // la case est vide
      std::string _mot = mot;
      std::string h_iterator = hand;
      unsigned int _case_curr = case_curr;
      remove_duplicate(h_iterator);
      for(unsigned int i =0; i<h_iterator.size(); i++){
        Node* curr = n;
        char pcurr = h_iterator[i];
        std::string h = hand;
        remove(pcurr, h);
        //std::cout<<"pcurr = la main du joueur "<<pcurr<<std::endl;
        if( curr->suffixes.count(p) > 0  ){
          plus = true;
          curr = curr->suffixes.at(p);
          std::cout<<"in else addPlus " <<std::endl;          
          mot = reverseStr(mot);
          if(curr->isWord) {
            Coups c(case_depart, mot, orientation);
            tab.push_back(c);
          }

          if(orientation){
            _case_curr += 15;
          } else{
            _case_curr++;
          }
          _case_curr = case_curr;
        }
        if( curr->suffixes.count(pcurr) > 0  ) {
          curr = curr->suffixes.at(pcurr);
          //std::cout<<"in else pcurr "<< pcurr <<std::endl;          
          mot += pcurr;

          if(curr->isWord) {
            Coups c(case_depart, mot, orientation);
            tab.push_back(c);
          }

          if(orientation){
            _case_curr += 15;
          } else{
            _case_curr++;
          }

          //std::cout<<"avant de faire l'appel recursif, "<<h<<std::endl; 
          //std::cout<<"le mot est "<<mot<<std::endl;
          std::cout<<"la case courrente est "<<case_curr<<std::endl;
          liste_coups_rec(curr, h, case_depart, _case_curr, mot, orientation, plus, tab);
        }
        mot = _mot;
        _case_curr = case_curr;
      }
    }
  }
}

void Game::liste_coups(std::string hand, std::vector<Coups>& tab1 /*, std::vector<Coups>& tab2*/){
  //for(unsigned int case_depart=0; case_depart<225; case_depart++){
    //if(board.spots[case_depart].letter != 0){
      std::string mot = ""; 
      unsigned int case_depart = 17;
      unsigned int case_curr = case_depart;
      liste_coups_rec(lexicon.root, hand, case_depart, case_curr, mot, false, false, tab1);
    //  liste_coups_rec(lexicon.root, hand, case_depart, case_curr, mot, true, false, tab2);
    //}

  //}
  /*
  std::string mot = ""; 
  unsigned int case_depart = 15; // 15;
  unsigned int case_curr = case_depart;
  liste_coups_rec(lexicon.root, hand, case_depart, case_curr, mot, false, false, tab);
  */
  //printArray(tab);
	/*for (unsigned int i = 0; i < tab.size(); i++) {
		std::cout << tab.at(i).mot <<" "<<std::endl;
	}*/

  std::cout<<"the tab length is "<<tab1.size()/*+tab2.size()*/<<std::endl;
}

/*
static void generate(Spot position,  std::string& word, std::string rack, Node* arc){
  if(! position.letter == 0){
    goOn(position, position.letter, word, rack, n->suffixes.at(i)), arc);
  } else if(rack.size()>0){
    for(char letter: rack){
      if(alllowed(letter)){
        goOn(position, letter, word, remove(letter, rack), arc->suffixes.[i], arc);
      }
    }
  }
}


static void goOn(Spot position, char letter, std::string word, std::string rack, Node* nArc,
                                                         Node* oArc, std::vector<Coups> tab){
  if ( positon.x <= 0 && position.y <= 0){
    word = letter + word;
    if(oArc->suffixes.count(letter) > 0){
      Coups c(position, mot, orientation);
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
      Coups c(position, mot, orientation);
      tab.push_back(c);
    }
    if(nArc != nullptr && (position.i++) >0){
      generate(position, word, rack, nArc);
    }
  
  }

}

*/


void Game::moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
          std::string& mot, bool orientation, bool plus, std::vector<Coups>& tab, std::stack <State>& moves){

	if(!moves.empty()) moves.pop();

	char pcurr;
  Node* curr;
  char p = '+';
  if(board.spots[case_curr].letter != 0){
      //si la case n'est pas vide
		curr = n;

		pcurr = board.spots[case_curr].letter;
		if( curr->suffixes.count(pcurr) > 0) {
			curr = curr->suffixes.at(pcurr);
			mot += pcurr;
			if(curr->isWord) {
			  //std::cout<<"j'ai trouvé un mot qui est "<<mot<<std::endl;
			  Coups c(case_depart, mot, orientation);
			  tab.push_back(c);
			}

			// on suit le sens inverse de la lecture
			if(!plus){
				//on se deplace verticalement
				if(orientation){
          case_curr-= 15;
          } else{
          //on se deplace horizontalement
            case_curr--;
          }
        } else{
          //on se deplace verticalement
          if(orientation){
          case_curr+= 15;
          } else{
          //on se deplace horizontalement
            case_curr++;
          }
        }
        State s(hand, curr, case_curr); 
        moves.push(s);

        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
      }
    } else{
		//std::cout<<"la case est vide "<<case_curr<<std::endl; 
		// la case est vide
    curr = n;
		if( curr->suffixes.count(p) > 0  ) {
			curr = curr->suffixes.at(p);
			mot = reverseStr(mot);
			plus = true;
			case_curr = case_depart;
			if(orientation){
					case_curr+= 15;
				} else{
					//on se deplace horizontalement
					case_curr++;
			}
			
			State s(hand, curr, case_curr); 
			moves.push(s);

			std::cout<<"la case courrente est "<<case_curr<<std::endl;
			moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
      } else{
      std::string _mot = mot;
      std::string h_iterator = hand;
      unsigned int _case_curr = case_curr;
      remove_duplicate(h_iterator);
      for(unsigned int i =0; i<h_iterator.size(); i++){
        Node* curr = n;
        char pcurr = h_iterator[i];
        std::string h = hand;
        remove(pcurr, h);
        //std::cout<<"pcurr = la main du joueur "<<pcurr<<std::endl;
        if( curr->suffixes.count(pcurr) > 0  ) {
          curr = curr->suffixes.at(pcurr);
          //std::cout<<"in else pcurr "<< pcurr <<std::endl;          
          mot += pcurr;

          if(curr->isWord) {
            unsigned int next = case_curr;
            if(!plus){
              //on se deplace verticalement
              if(orientation){
                next-= 15;
              } else{
                //on se deplace horizontalement
                next--;
              }
            } else{
                //on se deplace verticalement
              if(orientation){
                next+= 15;
              } else{
                //on se deplace horizontalement
                next++;
              }
            }
            if(board.spots[next].letter == 0){
              Coups c(case_depart, mot, orientation);
              tab.push_back(c);
            }
          }
          
            // on suit le sens inverse de la lecture
          if(!plus){
              //on se deplace verticalement
            if(orientation){
              case_curr-= 15;
            } else{
              //on se deplace horizontalement
              case_curr--;
            }
          } else{
              //on se deplace verticalement
            if(orientation){
              case_curr+= 15;
            } else{
              //on se deplace horizontalement
              case_curr++;
            }
          }
          State s(hand, curr, case_curr); 
          moves.push(s);
          
          std::cout<<"la case courrente est "<<case_curr<<std::endl;
          moves_list_rec(curr, h, case_depart, _case_curr, mot, orientation, plus, tab, moves);
        }
        mot = _mot;
        _case_curr = case_curr;
      }
    }
  }
}

void Game::moves_list(std::string hand, std::vector<Coups>& tab1, std::stack <State>& moves){
/*  
  for(unsigned int case_depart=0; case_depart<225; case_depart++){
	  bool orientation;
	  bool plus = false;
	  unsigned int case_curr;
	  std::vector<Coups> tab_h;
	  std::vector<Coups> tab_v;
    if(board.spots[case_depart].letter == 0 && board.spots[case_depart+1].letter != 0 && board.spots[case_depart-1].letter != 0){
      orientation = false;
      case_curr = case_depart;
      std::string mot = ""; 
      moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, tab_h);
    }
	
    if(board.spots[case_depart].letter == 0 && board.spots[case_depart+15].letter != 0 && board.spots[case_depart-15].letter != 0){
      orientation = true;
      case_curr = case_depart;
      std::string mot = ""; 
      moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, tab_v);
    }
  }
  */

  unsigned int case_depart = 20;
	bool orientation;
	bool plus = false;
  orientation = false;
	unsigned int case_curr = case_depart;
  std::string mot = ""; 
  moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, tab1, moves);

}

Game::~Game(){

}