#pragma once
#include <map>

class Node {
  private: 
    bool terminal;
//    char value;
  
  public:

    std::map<char, Node*> children;

    Node();
    Node(bool _t);

    ~Node();
  
    char getValue();

    // void setValue(char _v);

    bool isTerminal();

    void setTerminal(bool _t);
  
};

