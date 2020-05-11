#include "game.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

#include <time.h>

int main(int argc, char** argv)
{
  unsigned int sleep_time = 0;
  bool use_slow = false;

  bool enable_suzette_txt = false;
  bool enable_suzette_file = false;
  std::string txt_board = "";
  std::string txt_hand = "";
  
  if(argc >= 2){
    if (!strcmp(argv[1], "--suzette-text")){
      if(argc >= 4){
        std::string str_board(argv[2]);
        txt_board = str_board;

        std::string str_hand(argv[3]);
        txt_hand = str_hand;
        
        if( !is_board_valid(txt_board) ){
          std::cerr << "\nThe given board does not match the requested format!\nFor help, use option --help\n" << std::endl;
          exit(1);
        }
        if( !is_hand_valid(txt_hand)){
          std::cerr << "\nThe given hand does not match the requested format!\nFor help, use option --help\n" << std::endl;
          exit(1);
        }
        
        std::cout << "\nin SuzetteText option" << std::endl;
        enable_suzette_txt = true;
      }else{
        std::cerr << "\nERROR: need arguments: --suzette-text [board] [hand]\nFor help, use option --help\n" << std::endl;
        exit (1);
      }
    }else if (!strcmp(argv[1], "--suzette-file")){
      if(argc >= 3){
        std::string str_file;
        std::string filepath(argv[2]);
        bool openedFile = store_file_to_string(filepath, str_file);
        if(!openedFile) exit(1);
        split_string(str_file, txt_board, txt_hand);

        if( !is_board_valid(txt_board) ){
          std::cerr << "\nThe given board does not match the requested format!\nFor help, use option --help\n" << std::endl;
          exit(1);
        }
        if( !is_hand_valid(txt_hand)){
          std::cerr << "\nThe given hand does not match the requested format!\nFor help, use option --help\n" << std::endl;
          exit(1);
        }
        
        std::cout << "\nin SuzetteFile option" << std::endl;
        enable_suzette_file = true;
      }else{
        std::cerr << "\nERROR: need arguments: --suzette-file [file_name]\nFor help, use option --help\n" << std::endl;
        exit (1);
      }
    }else if (!strcmp(argv[1], "--slow")) {
      use_slow = true;
      sleep_time = 1;
      if(argc >= 3){
        sleep_time = atoi(argv[2]);
      }
      std::cout << "in slow mode with time = " << sleep_time << std::endl;
    }else if ( argc >= 2 && !strcmp(argv[1], "--help")) {
      std::cout << "Help menu :\n"
                << "-----------\n\n"
                << "Options* :\n"
                << "----------\n"
                << "--slow [number_of_seconds: optional]\n"
                << "--suzette-text [board] [hand]\n"
                << "--suzette-file [file_name]\n"
                << "* You can use only one option at a time\n\n"
                << "Formats : \n"
                << "---------\n"
                << "[board]     => 225 characters, using dots for empty cells and capitalized letters for the used tiles\n"
                << "[hand]      => [1,7] characters, using only capitalized letters (with no spaces!)\n"
                << "[file_name] => path to file containing the [board] [hand] (following the previous formats)\n";
      exit (1);
    }else{
      std::cerr << "\nERROR: unknown option\nFor help, use option --help\n" << std::endl;
      exit (1);
    }
  }

  //uncomment in the final version
  //srand(time(NULL));

  Game game;

  std::stringstream ss ;

  Coups coup(0, "", true, 0);

  //suzette mode
  if(enable_suzette_file || enable_suzette_txt){

    bool empty_board = true;

    for(unsigned int i = 0; i < 225; i++){
      char c = txt_board[i];
      if(c >= 'A' && c <= 'Z'){
        game.board.spots[i].letter = c;
        empty_board = false;
      }
    }

    game.player.setNbHandLetters(txt_hand.size());

    std::cout << game.board << std::endl;

    if(empty_board)
      coup = game.find_first_move(txt_hand);
    else
      coup = game.find_best_move(txt_hand);

    game.adapt_word(coup.spot, coup.orientation, coup.mot);

    std::cout << "hand = " << txt_hand << std::endl;
    std::cout << "word = " << coup.mot << std::endl;
    std::cout << "score = " << coup.score <<std::endl;

    game.board.placeWord(ss, coup.orientation, coup.spot/15, coup.spot%15, coup.mot);
    game.board.load(ss);

    std::cout << "used letters = " << coup.mot << " ( " << coup.mot.size() << " letters ) " << std::endl;

    std::cout << game.board << std::endl;
  }
  //normal mode
  else{
    system("exec rm -r ./data/boards/*");

    std::cout << game.board << std::endl;
  
    bool playingGame = true;
    unsigned int iteration_counter = 0;
    unsigned int used_tiles = 0;

    while( playingGame || game.player.handToString().size() > 0 ){
      
      if(iteration_counter <= 9)
        std::cout << "_________________________" << " iteration = 0"<< iteration_counter<<" __________________________\n" << std::endl;
      else
        std::cout << "_________________________" << " iteration = "<< iteration_counter<<" __________________________\n" << std::endl;

      std::cout << "hand = " << game.player.handToString() << std::endl;

      if(iteration_counter == 0)
        coup = game.find_first_move(game.player.handToString());
      else
        coup = game.find_best_move(game.player.handToString());

      std::string originalWord = coup.mot;

      game.score += coup.score;

      game.adapt_word(coup.spot, coup.orientation, coup.mot);

      std::cout << "word = " << coup.mot << " ( " << originalWord << " )" << ", score = " << coup.score <<" "<<std::endl;

      game.board.placeWord(ss, coup.orientation, coup.spot/15, coup.spot%15, coup.mot);
      game.board.load(ss);

      std::cout << "used letters = " << coup.mot << " ( " << coup.mot.size() << " letters ) " << std::endl;

      used_tiles += coup.mot.size();
      std::cout << "total used tiles = " << used_tiles << std::endl ;

      playingGame = game.player.replaceLetters(coup.mot);
      
      std::cout << "total score = " << game.score << std::endl;

      std::cout << game.board << std::endl;
      std::ofstream myfile;
      std::string s_iteration_counter = std::to_string(iteration_counter);
      std::string file_name = "./data/boards/board";
      file_name += s_iteration_counter;
      file_name += ".txt";
      myfile.open (file_name);
      game.board.save(myfile, game.player.handToString());
      myfile.close();

      //OPTIONS
      if(use_slow){
        std::chrono::milliseconds timespan(sleep_time*1000);
        std::this_thread::sleep_for(timespan);
      }
      
      iteration_counter++;
    }
  }
  exit (0);
}

