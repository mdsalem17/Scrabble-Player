#include "Node.hpp"

  Node::Node(){
    terminal = false;
  }

  Node::Node(bool _t){
    terminal = _t;
  }

  bool Node::isTerminal(){
    return terminal;
  }

  void Node::setTerminal(bool _t){
    terminal = _t;
  }
/**
  char Node::getValue(){
    return value;
  }

  void Node::setValue(char _v){
    value = _v;
  }
**/
  Node::~Node(){
    children.clear();
  }

