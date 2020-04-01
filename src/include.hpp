#pragma once
#include <string>
#include <vector>
#include <iostream>
    
std::pair<std::string, std::string> splitString(std::string word, unsigned int position);
std::string reverseStr(std::string str);
void printArray(std::vector<std::string> input);
void remove(char c, std::string& word);
void remove_duplicate(std::string& str);