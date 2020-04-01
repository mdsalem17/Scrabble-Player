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

std::string reverseStr(std::string word){ 
    unsigned int n = word.length();
    std::string str = word;
    for (unsigned int i = 0; i < n; i++) 
        str[i] = word[n - i - 1];
    return str;
}

void printArray(std::vector<std::string> input){
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
        while ( j < s.size() )
        {
            if ( s[i] == s[j] )
            {
                s.erase( j, 1 );
            }
            else
            {
                ++j;
            }
        }
    }
         
}