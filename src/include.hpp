#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// "splitString" permet de diviser un mot en deux parties à partir de la position
std::pair<std::string, std::string> splitString(std::string word, unsigned int position);

//permet d'inverser une chaine de caractères
std::string reverse_str(std::string str);

//affiche le contenu d'un tableau de chaine de caractères
void print_array(std::vector<std::string> input);

//permet de supprimer la première occurence du caractère c dans le mot word
void remove(char c, std::string& word);

//permet de supprimer tous les doublons
void remove_duplicate(std::string& str);

//
bool is_board_valid(std::string& board);

//
bool is_hand_valid(std::string& hand);

//
bool store_file_to_string(const std::string& file_path, std::string& text);

//
void extract_board_hand(const std::string& text, std::string& board, std::string& hand);