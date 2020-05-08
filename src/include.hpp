#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
    
std::pair<std::string, std::string> splitString(std::string word, unsigned int position);
std::string reverseStr(std::string str);
void printArray(std::vector<std::string> input);
void remove(char c, std::string& word);
void remove_duplicate(std::string& str);

bool is_board_valid(std::string& board);
bool is_hand_valid(std::string& hand);
bool store_file_to_string(const std::string& file_path, std::string& text);
void split_string(const std::string& text, std::string& board, std::string& hand);