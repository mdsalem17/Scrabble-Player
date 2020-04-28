#include "game.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include <time.h>

int main() {

  //srand(time(NULL));

  Game game;

  std::stringstream ss ;

  std::string first_word = "BATEAU";
  game.board.placeWord(ss, 1, 7, 7, first_word);
  game.board.load(ss);

  std::cout << game.player.handToString() << std::endl;

  std::cout << game.board << std::endl;

  bool playingGame = true;
  unsigned int compteur = 0;
  while(playingGame && game.player.bag.getNbLetters() > 0 ){
    
    std::cout << "++++++++++++++++++++++++++++++++++++++++"
              << "iteration = "<< compteur<<"+++++++" << std::endl;


    std::cout << game.player.handToString() << std::endl;

    Coups coup = game.find_best_move(game.player.handToString());

    std::cout << "mot = " << coup.mot << ", score = " << coup.score <<" "<<std::endl;
    std::cout << "i = " << coup.spot/15 << ", j = " << coup.spot%15 <<" "<<std::endl;

    game.score += coup.score;

    std::cout << "nb tiles total = " << game.player.bag.getNbLetters() << std::endl;
    game.adapt_word(coup.spot, coup.orientation, coup.mot);

    std::cout << "--" << coup.mot << "--" << std::endl;

    game.board.placeWord(ss, coup.orientation, coup.spot/15, coup.spot%15, coup.mot);
    game.board.load(ss);

    playingGame = game.player.replaceLetters(coup.mot);

    std::cout << "score total = " << game.score << std::endl;

    std::cout << game.board << std::endl;

    std::ofstream myfile;
    myfile.open ("board.txt");
    game.board.save(myfile);
    myfile.close();
    compteur++;

  }

}
