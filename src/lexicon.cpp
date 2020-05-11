#include "lexicon.hpp"

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

void Node::size(unsigned int& curr) {
    if(isWord == true) curr++;
    for (std::unordered_map <char, Node*>::iterator it = suffixes.begin(); it != suffixes.end(); ++it){
        it->second->size(curr);
    }
}

void Lexicon::add(const std::string& word) {
    ensure_node_exists(word)->isWord = true;
    length++;
}

bool Lexicon::contains_prefix(const std::string& prefix) const {
    return find_node(prefix) != nullptr;
}

bool Lexicon::contains(const std::string& word) const {
    const Node *found = find_node(word);
    return found != nullptr && found->isWord;
}

const Node *Lexicon::find_node(const std::string& str) const {
    const Node *curr = root;
    for (unsigned int pos = 0; pos < str.size() && curr != nullptr; pos++) {
        if( curr->suffixes.count(str[pos]) > 0)
            curr = curr->suffixes.at(str[pos]);
        else curr= nullptr;
    }

    return curr;
}

Node *Lexicon::ensure_node_exists(const std::string& str) {
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

std::vector<std::string> Lexicon::load_from_file(){
    std::vector<std::string> array;
	std::string line;
	std::ifstream myfile ("./data/dico.txt");
	if (myfile.is_open()){
		while (getline (myfile,line)){
			array.push_back(line);
		}
		myfile.close();
	} else std::cout << "Unable to open file"<<std::endl;

    return array;
}

static void add_plus(std::string word, std::vector<std::string>& array){
    for(unsigned int i=0; i < word.size(); i++){
        std::pair<std::string, std::string> p = splitString(word, i);
        array.push_back(reverse_str(p.first)+ "+" + p.second);
    }
}

void Lexicon::download_lexicon(){
    std::vector<std::string> lexicon;
    std::vector<std::string> array = load_from_file();
    for(std::string word: array){
        add_plus(word, lexicon);
        for(std::string curr: lexicon){
            add(curr);
        }
        lexicon.clear();
    }
    std::cout << "Dictionary has been successfully downloaded" << std::endl;
}

unsigned int Lexicon::size() const{
    unsigned int n_curr =0;
    root->size(n_curr);

    return n_curr;
}