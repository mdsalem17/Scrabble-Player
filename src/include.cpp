#include "include.hpp"

std::pair<std::string, std::string> splitString(std::string word, unsigned int position){
    if(position > word.size()){
        std::cout<<"Position too big"<<std::endl;
        exit(EXIT_FAILURE);
    }else {
        std::string subWord1="";
        std::string subWord2="";
        for(unsigned int i=0; i<word.size(); i++){
            if(i<=position){
                subWord1+=word[i];
            }else{
                subWord2+=word[i];
            }
        }
        return std::make_pair(subWord1, subWord2);
    }
}

std::string reverse_str(std::string word){ 
    unsigned int n = word.length();
    std::string str = word;
    for (unsigned int i = 0; i < n; i++) 
        str[i] = word[n - i - 1];
    return str;
}

void print_array(std::vector<std::string> input){
	for (unsigned int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) <<" "<<std::endl;
	}
}

void remove(char c, std::string& word){
  std::string m = "";
  bool first = false;
  for(unsigned int i=0; i<word.size(); i++){
    if(first) m+= word[i];
    else if(word[i] == c) first = true;
    else m += word[i];
  }
  word = m;
}

void remove_duplicate(std::string& s){ 
    for ( std::string::size_type i = 0; i < s.size(); i++ ){
        std::string::size_type j = i + 1;
        while ( j < s.size() ) {
            if ( s[i] == s[j] ){
                s.erase( j, 1 );
            } else{
                ++j;
            }
        }
    }
}

bool is_board_valid(std::string& board){
    if(board.size() == 225){
        for(unsigned int i = 0; i < 225; i++){
            if(!((board[i] >= 'A' && board[i] <= 'Z') || board[i] == '.'))
                return false;
        }
    }else{
        return false;
    }

    return true;
}

bool is_hand_valid(std::string& hand){
    if(!hand.empty() && hand.size() <= 7){
        for(unsigned int i = 0; i < hand.size(); i++){
            if(!(hand[i] >= 'A' && hand[i] <= 'Z'))
                return false;
        }
    }else{
        return false;
    }

    return true;
}

bool store_file_to_string(const std::string& file_path, std::string& text){
    std::ifstream in(file_path);
    if (in) {
        in.seekg(0, std::ios::end);
        size_t len = in.tellg();
        in.seekg(0);
        std::string contents(len + 1, '\0');
        in.read(&contents[0], len);
        text = contents;

    }else{
        std::cout << "ERROR : cannot open file" << std::endl;
        return false;
    }

    return true;
}

void extract_board_hand(const std::string& text, std::string& board, std::string& hand){
    
    board = "";
    hand = "";
    
    bool reachedDelim = false;

    for(unsigned int i = 0; i < text.size()-1; i++){
        if(text[i] == ' '){
            reachedDelim = true;
            i++;
        }
        
        if(!reachedDelim){
            board += text[i];
        }else{
            hand += text[i];
        }
    }
}