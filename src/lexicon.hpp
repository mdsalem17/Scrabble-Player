#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "include.hpp"

struct Node {
    bool isWord;
    std::unordered_map<char, Node*> suffixes;
    void display();
    void size(unsigned int& curr);
    Node();
    ~Node();
};

class Lexicon {
    public:
        unsigned int length;
        
        Lexicon() {
            root = nullptr;
        }

        ~Lexicon() { 
            delete root;
        }

        void add(const std::string& word);
        unsigned int size() const;
        bool contains(const std::string& word) const;
        bool containsPrefix(const std::string& prefix) const;
        void display() const;
        std::vector<std::string> loadFromFile();
        void addPlus(std::string word, std::vector<std::string>& array);
        void downloadLexicon();
    private:
        Node *root;   
        const Node *findNode(const std::string& str) const;
        Node *ensureNodeExists(const std::string& str);
};