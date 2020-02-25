#include "lexicon.hpp"
#include <iostream>
#include <fstream>

Node::Node() {
    isWord = false;
}
Node::~Node() {
    for(std::unordered_map<char, Node*>::iterator itr = suffixes.begin();
                                    itr != suffixes.end(); itr++){
        delete (itr->second);
    }
    suffixes.clear();
}

void Lexicon::add(const std::string& word) {
 ensureNodeExists(word)->isWord = true;
}

bool Lexicon::containsPrefix(const std::string& prefix) const {
return findNode(prefix) != nullptr;
}

bool Lexicon::contains(const std::string& word) const {
 const Node *found = findNode(word);
 return found != nullptr && found->isWord;
}

const Node *Lexicon::findNode(const std::string& str) const {
    const Node *curr = root;
    for (unsigned int pos = 0; pos < str.size() && curr != nullptr; pos++) {
        if( curr->suffixes.count(str[pos]) > 0)
            curr = curr->suffixes.at(str[pos]);
        else curr= nullptr;
    }

    return curr;
}

Node *Lexicon::ensureNodeExists(const std::string& str) {
    Node **currp = &root;
    unsigned int pos = 0;
    while (true) {
        if (*currp == nullptr) *currp = new Node;
        if (pos == str.size()) break;
        currp = &((*currp)->suffixes[str[pos]]);
        pos++;
    }
    return *currp;
}

void Node::display() {
    for (std::unordered_map <char, Node*>::iterator it = suffixes.begin(); it != suffixes.end(); ++it){
    std::cout << it->first << "| ";
    std::unordered_map<char, Node*> &internal_map = it->second->suffixes;
    for (std::unordered_map<char, Node*>::iterator it2 = internal_map.begin(); it2 != internal_map.end(); ++it2){
        if (it2 != internal_map.begin())
            std::cout << ", ";
        std::cout << it2->first;
        if(isWord) std::cout<<"&";
        std::cout<<":" << it2->second;
    }
    std::cout <<"| ";
    }
}

void Lexicon::display() const{
    std::cout << std::endl << "Start printing the Lexicon : " << std::endl;

    for (std::unordered_map <char, Node*>::iterator it = root->suffixes.begin(); it != root->suffixes.end(); ++it){
    std::cout << it->first << " : ";
    it->second->display();
    std::cout << std::endl;
    }
}

void Lexicon::loadFromFile(){
	std::string line;
	std::ifstream myfile ("./data/dico.txt");
	if (myfile.is_open()){
		while (! myfile.eof() )
		{
			getline (myfile,line);
			add(line);
		}
		myfile.close();
	} else std::cout << "Unable to open file"<<std::endl;
}