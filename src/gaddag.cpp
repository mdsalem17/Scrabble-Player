#include "gaddag.hpp"
    
  
  Gaddag::Gaddag(std::vector<std::string> lexicon){
    loadFromArray(lexicon);
  };

  //default initialization, charging the lexicon from the file
  void Gaddag::loadFromArray(std::vector<std::string> lexicon){
    for(std::string word : lexicon){
      std::cout<<"the word to insert: "<<word<<std::endl;
      Node* temp = root;
      for(unsigned int i = 0; i < word.size(); i++) {
        if(i==0) std::cout<<"start the insertion"<<std::endl;
        std::cout << "[ " << i << "| " << word[i] << std::endl;
//        temp->setValue(word[i]);
        if(i == word.size()-1) {
          std::cout<<"end of the insertion"<<std::endl;
          temp->children[word[i]] = new Node(true);
        }
        else temp = temp->children[word[i]];
      }
    }
  }

  void Gaddag::display() const{
      for (auto& it: root->children)
    {
      std::cout << "[" << it.first << ", " << it.second << "]" << std::endl;
    }
  }
