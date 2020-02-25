#pragma once
#include <unordered_map>
#include <string>

struct Node {
    bool isWord;
    std::unordered_map<char, Node*> suffixes;
    void display();
    Node();
    ~Node();
};

class Lexicon {
public:
    Lexicon() {
        root = nullptr;
    }

    ~Lexicon() { 
        delete root;
    }

    void add(const std::string& word);
    bool contains(const std::string& word) const;
    bool containsPrefix(const std::string& prefix) const;
    void display() const;
    void loadFromFile();

private:
    Node *root;
    const Node *findNode(const std::string& str) const;
    Node *ensureNodeExists(const std::string& str);
};