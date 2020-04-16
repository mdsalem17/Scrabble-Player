#include "game.hpp"

#include <iostream>
#include <sstream>

#include <time.h>

int main() {

  srand(time(NULL));

  Game game;

  std::stringstream ss ;

  std::string first_word = "KHALED";
  game.board.placeWord(ss, 1, 7, 7, first_word);
  game.board.load(ss);

  std::cout << game.player.handToString() << std::endl;

  std::cout << game.board << std::endl;

  bool playingGame = true;

  //bool exists = game.check_word_not_on_board(112, 1, "HK+ALED");

  //std::cout << "word does not exist on board = " << exists << std::endl;

  while(playingGame){
    
    std::cout << game.player.handToString() << std::endl;

    Coups coup = game.trouver_meilleur_coups(game.player.handToString());

    std::cout << "mot = " << coup.mot << ", score = " << coup.score <<" "<<std::endl;
    std::cout << "i = " << coup.spot/15 << ", j = " << coup.spot%15 <<" "<<std::endl;

    game.score += coup.score;
    game.adapt_word(coup.spot, coup.orientation, coup.mot);

    game.board.placeWord(ss, coup.orientation, coup.spot/15, coup.spot%15, coup.mot);
    game.board.load(ss);

    playingGame = game.player.replaceLetters(coup.mot);

    std::cout << "score total = " << game.score << std::endl;

    std::cout << game.board << std::endl;

  }

}
