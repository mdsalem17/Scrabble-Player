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

  std::cout<<case_curr<<" et le mot du crossword = "<<word<<std::endl;

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

    {
      std::string _word = "";
      unsigned int _case = case_curr;

      _word += word[i];
      std::cout<<case_curr<<" et le mot du crossword = "<<_word<<std::endl;

      do{
        if( moves_available(_case, !orientation, false) ){
          deplacement(!orientation, false, _case);
          if(board.spots[_case].letter != 0){
            _word +=board.spots[_case].letter;
          }
        }
      } while( board.spots[_case].letter != 0 );

      std::cout<<case_curr<<" et le mot avant le plus du crossword = "<<_word<<std::endl;

      _case = case_curr;
      if( _word != ""){
        _word += "+";
      }
      if(moves_available(_case, !orientation, true))
        deplacement(!orientation, true, _case);

      while( board.spots[_case].letter != 0 && moves_available(_case, !orientation, true)){
        std::cout<<_case<<" et le spot du crossword = "<<_word<<std::endl;
        _word += board.spots[_case].letter;
        std::cout<<_case<<" et le spot du crossword = "<<_word<<std::endl;
        deplacement(!orientation, true, _case);
      }

      std::cout<<case_curr<<" et le mot du crossword = "<<_word<<std::endl;

      if(lexicon.contains(_word)){
        std::pair<unsigned int, std::string> p(case_curr, _word);
        tab.push_back(p);
      }
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
  std::cout<<"the score before addding crosswords = "<<_score<<std::endl;

  for(std::pair<unsigned int, std::string> p : tab){
    unsigned int _s = word_score(p.first, p.second, !orientation);
    std::cout<<"the score of the crossword = "<<_s<<std::endl;
    _score += _s;

  }
  
  std::cout<<" word score = "<<_score<<std::endl;
  if(empty) bingo = 50;

  return _score + bingo;
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
        if(curr->isWord) {
          Coups c(case_depart, mot, orientation);
          tab.push_back(c);
        }
        
      std::cout<<"pcurr -> "<<pcurr<<std::endl;
      std::cout<<"case_curr -> "<<case_curr<<std::endl;
      std::cout<<"word "<<mot<<std::endl;
      if(moves_available(case_curr, orientation, plus)){
        deplacement(orientation, plus, case_curr);
        State s(hand, curr, case_curr);
        moves.push(s);

        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
      }  else{
        if( curr->suffixes.count(p) > 0 ) {
          curr = curr->suffixes.at(p);
          mot += p;
          plus = true;
          case_curr = case_depart;
              
          if(moves_available(case_curr, orientation, plus)){
            deplacement(orientation, plus, case_curr);
            State s(hand, curr, case_curr); 
            moves.push(s);

            moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
          }
        }
      }
    }
  }  else{
    std::cout<<case_curr<<" -> est une case vide; debut de la recherche "<<std::endl;
		if( curr->suffixes.count(p) > 0 ) {
			curr = curr->suffixes.at(p);
      mot += p;
      std::cout<<"mot => "<<mot<<std::endl;
			plus = true;
			case_curr = case_depart;
			
      if(moves_available(case_curr, orientation, plus)){
        deplacement(orientation, plus, case_curr);
        State s(hand, curr, case_curr); 
        moves.push(s);
        moves_list_rec(curr, hand, case_depart, case_curr, mot, orientation, plus, tab, moves);
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
              if(curr->isWord) {
                Coups c(case_depart, mot, orientation);
                tab.push_back(c);
              }
              if(moves_available(case_curr, orientation, plus)){
                  deplacement(orientation, plus, case_curr);
                  std::cout<<" je me suis déplacé"<<std::endl;
                  std::cout<<"word "<<mot<<std::endl;
                  std::cout<<"box "<<case_curr<<std::endl;
                  State s(hand, curr, case_curr); 
                  moves.push(s);
                    
                  moves_list_rec(curr, h, case_depart, case_curr, mot, orientation, plus, tab, moves);
              } else{
                std::cout<<" je n'ai pas pu me déplacer"<<std::endl;
                std::cout<<"word "<<mot<<std::endl;
                std::cout<<"box "<<case_curr<<std::endl;

                if( curr->suffixes.count(p) > 0 ) {
                  curr = curr->suffixes.at(p);
                  mot += p;
                  plus = true;
                  case_curr = case_depart;
                  if(moves_available(case_curr, orientation, plus)){
                    deplacement(orientation, plus, case_curr);
                    std::cout<<" je me suis déplacé"<<std::endl;
                    std::cout<<"word "<<mot<<std::endl;
                    std::cout<<"box "<<case_curr<<std::endl;
                    State s(hand, curr, case_curr); 
                    moves.push(s);
                    moves_list_rec(curr, h, case_depart, case_curr, mot, orientation, plus, tab, moves);
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

void Game::moves_list(std::string hand, std::vector<Coups>& tab1, std::stack <State>& moves){

  unsigned int case_depart = 128;
	bool orientation;
	bool plus = false;
  orientation = true;
	unsigned int case_curr = case_depart;
  std::string mot = "";
  moves_list_rec(lexicon.root, hand, case_depart, case_curr, mot, orientation, plus, tab1, moves);
}

Game::~Game(){

}