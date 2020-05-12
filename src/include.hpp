#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// "split_string" permet de diviser un mot en deux parties à partir de la position
std::pair<std::string, std::string> split_string(std::string word, unsigned int position);

// "reverse_str" permet d'inverser une chaine de caractères
std::string reverse_str(std::string str);

// "print_array" affiche le contenu d'un tableau de chaine de caractères
void print_array(std::vector<std::string> input);

// "remove" permet de supprimer la première occurence du caractère c dans le mot word
void remove(char c, std::string& word);

// "remove_duplicate" permet de supprimer tous les doublons
void remove_duplicate(std::string& str);

// "is_board_valid" permet de vérifier que le format du plateau est bien valide
bool is_board_valid(std::string& board);

// "is_hand_valid" permet de vérifier le format de la main que les lettres sont majuscules
bool is_hand_valid(std::string& hand);

// "store_file_to_string" permet de remplir un fichier avec un texte
bool store_file_to_string(const std::string& file_path, std::string& text);

// "extract_board_hand" permet d'extraire le plateau et la main partir du text
void extract_board_hand(const std::string& text, std::string& board, std::string& hand);

// "is_integer" renvoie vrai(true) si la chaine de caractères passée en paramètre
// contient que des valeurs entières
bool is_integer(const std::string& str);
