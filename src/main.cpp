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

  bool enable_suzette_case_depart = false;
  unsigned int suzette_case_depart = 0;

  bool enable_suzette_orientation = false;
  bool suzette_orientation = true;

  bool enable_suzette_plus = false;
  bool suzette_plus = false;
  
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

        for(unsigned int i = 3; i < (unsigned int) argc; i++){
          if(!strcmp(argv[i], "-vertical") || !strcmp(argv[i], "-v")){
            enable_suzette_orientation = true;
            suzette_orientation = true;
          }else if(!strcmp(argv[i], "-horizontal") || !strcmp(argv[i], "-h")){
            enable_suzette_orientation = true;
            suzette_orientation = false;
          }else if(!strcmp(argv[i], "-plus") || !strcmp(argv[i], "-p")){
            enable_suzette_plus = true;
            suzette_plus = true;
          }else if(!strcmp(argv[i], "-case") || !strcmp(argv[i], "-c")){
            if((unsigned)argc > i + 1 && !(atoi(argv[i]) > 225 )){ ///////////verify argv[i] is int not string, and if string exit(1)
              enable_suzette_case_depart = true;
              i++;
              suzette_case_depart = atoi(argv[i]);
              if(suzette_case_depart > 225){
                std::cerr << "Case needs to be a value betwen [0, 225]" << std::endl;
                exit(1);
              }
            }else{
              std::cerr << "\nERROR: use of this option -case [case_number]\nFor help, use option --help" << std::endl;
              exit(1);
            }
          }else{
            std::cerr << "\nERROR: unknown option\nFor help, use option --help" << std::endl;
            exit(1);
          }
          
        }
        std::cout << "suzette_case_depart = " << suzette_case_depart << std::endl;

        std::cout << "\nenable_suzette_file = " << enable_suzette_file << std::endl;
        std::cout << "enable_suzette_orientation = " << enable_suzette_orientation << ", orientation value = " <<  suzette_orientation << std::endl;
        std::cout << "enable_suzette_plus = " << enable_suzette_plus << ", plus value = " << suzette_plus << std::endl;
        std::cout << "enable_suzette_case_depart = " << enable_suzette_case_depart << ", case value = " << suzette_case_depart << std::endl;
        exit(1);

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

