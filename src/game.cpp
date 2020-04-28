#include "game.hpp"


Game::Game(){
    score = 0;
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

void Game::adapt_word(unsigned int& case_depart, bool orientation, std::string& mot){
  std::string word = "";
  unsigned int _case = case_depart;
  unsigned int i = 0;
  word += mot[i];
  i++;
  
  while( mot[i] != '+' && moves_available(_case, orientation, false)){
    word += mot[i];
    deplacement(orientation, false, _case);
    i++;
  };

  word = reverseStr(word);

  i++;
  while( i<mot.size()){
    word += mot[i];
    i++;
  }

  std::cout<<"nouvelle case depart = "<<_case<<" et le mot = "<<word<<std::endl;
  case_depart = _case;
  mot = word;
}

// la case_curr n'est pas vide, alors on n'a pas besoin de préciser le caractère c
bool Game::verify_crosswords(unsigned int case_curr, bool orientation,  char c){
  std::string word = "";
  unsigned int _case = case_curr;

  if( !isblank(c) ){
    word += c;
  } else {
    word +=board.spots[_case].letter;
  }

  do{
    if( moves_available(_case, !orientation, false) ){
      deplacement(!orientation, false, _case);
      if(board.spots[_case].letter != 0)
        word +=board.spots[_case].letter;
    }
  } while( board.spots[_case].letter != 0 );

  _case = case_curr;
  if( word != ""){
    word += "+";
  }
  if(moves_available(_case, !orientation, true))
    deplacement(!orientation, true, _case);

  while( board.spots[_case].letter != 0 && moves_available(_case, !orientation, true)){
    word += board.spots[_case].letter;
      deplacement(!orientation, true, _case);
  }

  return (word.size() == 2 && word[1] == '+') || word.empty() || lexicon.contains(word);
}

std::vector<std::pair<unsigned int, std::string>> Game::get_crosswords(unsigned int case_depart, std::string word, bool orientation){
  std::vector<std::pair<unsigned int, std::string>> tab;
  unsigned int case_curr = case_depart;
  bool plus = false;
  for(unsigned int i = 0; i < word.size(); i++ ){

    if(word[i] == '+'){
      plus = true;
      case_curr = case_depart;
      deplacement(orientation, plus, case_curr);
      i++;
    }

    std::string _word = "";
    unsigned int _case = case_curr;

    _word += word[i];

    do{
      if( moves_available(_case, !orientation, false) ){
        deplacement(!orientation, false, _case);
        if(board.spots[_case].letter != 0){
          _word +=board.spots[_case].letter;
        }
      }
    } while( board.spots[_case].letter != 0 );

    _case = case_curr;
    if( _word != ""){
      _word += "+";
    }
    if(moves_available(_case, !orientation, true))
      deplacement(!orientation, true, _case);

    while( board.spots[_case].letter != 0 && moves_available(_case, !orientation, true)){
      _word += board.spots[_case].letter;
      deplacement(!orientation, true, _case);
    }

    if(lexicon.contains(_word)){
      std::pair<unsigned int, std::string> p(case_curr, _word);
      tab.push_back(p);
    }

    deplacement(orientation, plus, case_curr);
  }

  return tab;
}

unsigned int Game::word_score(unsigned int case_depart, std::string word, bool orientation){
  unsigned int case_curr = case_depart;
  unsigned int i = 0;
  unsigned int letter_score = 0;
  unsigned int word_score = 0;
  unsigned int word_factor = 1;

  while(word[i] != '+'){
    letter_score = player.bag.getCharPoints(word[i]);
    letter_score = board.spots[case_curr].bonus.apply_letter(letter_score);
    word_factor = board.spots[case_curr].bonus.apply_word(word_factor);
    word_score += letter_score;
    deplacement(orientation, false, case_curr);
    i++;
  }
  
  case_curr = case_depart;
  deplacement(orientation, true, case_curr);
  i++;
  while(i < word.size()){
    letter_score = player.bag.getCharPoints(word[i]);
    letter_score = board.spots[case_curr].bonus.apply_letter(letter_score);
    word_factor = board.spots[case_curr].bonus.apply_word(word_factor);
    word_score += letter_score;
    deplacement(orientation, true, case_curr);
    i++;
  }


  return word_factor*word_score ;
}

unsigned int Game::play_score(unsigned int case_depart, std::string word, bool orientation, bool empty){
  unsigned int bingo = 0;
  
  std::vector<std::pair<unsigned int, std::string>> tab = get_crosswords(case_depart, word, orientation);
  unsigned int _score = word_score(case_depart, word, orientation);

  for(std::pair<unsigned int, std::string> p : tab){
    unsigned int _s = word_score(p.first, p.second, !orientation);
    _score += _s;
  }

  if(empty) bingo = 50;

  return _score + bingo;
}

void Game::moves_list_rec(Node* n, std::string hand, unsigned int case_depart, unsigned int &case_curr,
          std::string& mot, bool orientation, bool plus, Coups& meilleurCoup){

  std::cout << "case_curr = " << case_curr << std::endl;

	char pcurr;
  Node* curr = n;
  char p = '+';

  if(board.spots[case_curr].letter != 0){

		pcurr = board.spots[case_curr].letter;
    if( curr->suffixes.count(pcurr) > 0 ) {
      curr = curr->suffixes.at(pcurr);
      mot += pcurr;
      if(curr->isWord && hand.size() < player.getNbHandLetters() && mot.size() > 1) {
        Coups c(case_depart, mot, orientation, play_score(case_depart, mot, orientation, hand.empty()));
        if(c.score > meilleurCoup.score){
          meilleurCoup = c;
        }
      }

      if(moves_available(case_curr, orientation, plus)){
        deplacement(orientation, plus, case_curr);

        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, meilleurCoup);
      }  else{
        if( curr->suffixes.count(p) > 0 ) {
          curr = curr->suffixes.at(p);
          mot += p;
          plus = true;
          case_curr = case_depart;
              
          if(moves_available(case_curr, orientation, plus)){
            deplacement(orientation, plus, case_curr);

            moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, meilleurCoup);
          }
        }
      }
    }
  }  else{
		if( curr->suffixes.count(p) > 0 ) {
			curr = curr->suffixes.at(p);
      mot += p;
			plus = true;
			case_curr = case_depart;
			
      if(moves_available(case_curr, orientation, plus)){
        deplacement(orientation, plus, case_curr);

        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, meilleurCoup);
      }
    } else {
      std::string _mot = mot;
      std::string h_iterator = hand;
      unsigned int _case_curr = case_curr;
      remove_duplicate(h_iterator);
      for(unsigned int i =0; i<h_iterator.size(); i++){
        Node* curr = n;
        pcurr = h_iterator[i];
        std::string h = hand;
        remove(pcurr, h);
        if( curr->suffixes.count(pcurr) > 0 ) {
          if(verify_crosswords(case_curr, orientation, pcurr)){
            curr = curr->suffixes.at(pcurr);
            mot += pcurr;
              if(curr->isWord && mot.size() > 1) {
                Coups c(case_depart, mot, orientation, play_score(case_depart, mot, orientation, h.empty()));
                if(c.score > meilleurCoup.score){
                  meilleurCoup = c;
                }
              }
              if(moves_available(case_curr, orientation, plus)){
                  deplacement(orientation, plus, case_curr);

                  moves_list_rec(curr, h, case_depart, case_curr, mot, orientation, plus, meilleurCoup);
              } else{
                if( curr->suffixes.count(p) > 0 ) {
                  curr = curr->suffixes.at(p);
                  mot += p;
                  plus = true;
                  case_curr = case_depart;
                  if(moves_available(case_curr, orientation, plus)){
                    deplacement(orientation, plus, case_curr);

                    moves_list_rec(curr, h, case_depart, case_curr, mot, orientation, plus, meilleurCoup);
                  }
                }   
              }
          }
        }
        mot = _mot;
        case_curr = _case_curr;
      }
    }
  }
}

Coups Game::moves_list(std::string hand, unsigned int case_depart, bool orientation){
 
  bool plus = false;
  unsigned int case_curr = case_depart;
  std::string mot = "";
  Coups meilleurCoup(0, "", true, 0);

  moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, meilleurCoup);

  return meilleurCoup;
}

Coups Game::find_best_move(std::string hand){

  Coups meilleurCoup(0, "", true, 0);
  
  std::vector<Coups> tab_coups;

  for(unsigned int i = 0; i < 225; i++){
    unsigned int j = i;
    unsigned int k = i;
    unsigned int x = i;
    unsigned int y = i;
    if(board.spots[i].letter == 0){
      //Vertical sans plus
      if(moves_available(i, true, false)){
        deplacement(true, false, j);
        if(board.spots[j].letter != 0){
          j = i;
          std::cout << "case courante = " << i << " lettre = " << board.spots[i].letter << std::endl;
          tab_coups.push_back( moves_list(hand, j, true) );
          std::cout << "finished coup1" << std::endl;
        }
      }
      //Vertical avec plus
      if(moves_available(i, true, true)){
        deplacement(true, true, k);
        if(board.spots[k].letter != 0){
          k = i;
          std::cout << "case courante = " << j << " lettre = " << board.spots[j].letter << std::endl;
          tab_coups.push_back( moves_list(hand, k, true) );
          std::cout << "finished coup2" << std::endl;
        }
      }
      //Horizontal sans plus
      if(moves_available(i, false, false)){
        deplacement(false, false, x);
        if(board.spots[x].letter != 0){
          x = i;
          std::cout << "case courante = " << x << " lettre = " << board.spots[x].letter << std::endl;
          tab_coups.push_back( moves_list(hand, x, false) );
          std::cout << "finished coup3" << std::endl;
        }
      }
      //Horizontal avec plus
      if(moves_available(i, false, true)){
        deplacement(false, true, y);
        if(board.spots[y].letter != 0){
          y = i;
          tab_coups.push_back( moves_list(hand, y, false) );
          std::cout << "finished coup4" << std::endl;
        }
      }
    }
  }

  meilleurCoup = tab_coups.at(0);
  for(unsigned int i = 1; i < tab_coups.size(); i++){
    if(meilleurCoup.score < tab_coups.at(i).score){
      meilleurCoup = tab_coups.at(i);
    }
  }

  std::cout << "tab_coups size = " << tab_coups.size() << std::endl;

  return meilleurCoup;
}



Game::~Game(){

}