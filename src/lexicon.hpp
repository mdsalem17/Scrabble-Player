#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "include.hpp"

/*
Les arbres peuvent être utilisées comme implémentation sous-jacente d'un Lexicon, qui 
stocke une grande collection de mots et fournit des temps d'entrée et de recherche très 
efficaces. L'implémentation arborescente du Lexicon (proposée ci-dessous) permet de 
déterminer si un mot se trouve dans le lexique plus rapidement que vous ne pouvez 
utiliser une table de hachage, et elle offre un support naturel pour confirmer la 
présence de préfixes d'une manière que les tables de hachage ne peuvent pas.
Lorsque vous utilisez un arbre pour sauvegarder un Lexicon, les mots sont implicitement
représentés par l'arbre lui-même, chaque mot étant représenté comme une chaîne de liens
descendant de la racine. La racine de l'arbre correspond à la chaîne vide et chaque 
niveau successif du trie correspond au préfixe de la liste de mots entière formée en 
ajoutant une autre lettre à la chaîne représentée par son parent.
Le lien A descendant de la racine mène au sous-tri contenant tous les mots commençant
par A, le lien B de ce nœud mène au sous-tri contenant tous les mots commençant par AB,
etc.
Chaque nœud stocke un booléen qui est à true chaque fois que la sous-chaîne se termine
à ce point particulier est un mot valide.
*/


struct Node {
    // permet de savoir si le noeud correspond à un mot valide
    bool isWord;
    
    // permet de stocker tous les suffixes du nœud,
    // unordered_map correspond à une table de hachage permettant la meilleur efficacité
    // pour faire des opérations telles que find, insert, erase
    std::unordered_map<char, Node*> suffixes;

    //permet de caluler le nombre de mots existants (suffixes) à partir de ce nœud
    void size(unsigned int& curr);
    
    Node();
    ~Node();
};

class Lexicon {
    public:        
        Lexicon() {
            root = nullptr;
            length = 0;
        }

        ~Lexicon() { 
            delete root;
        }

        // "add" doit garantir qu'un nœud existe au nom de la séquence de caractères
        // fournie et que le champ isWord au sein de ce nœud est vrai. Elle s'appuie
        // sur "ensure_node_exists".
        void add(const std::string& word);

        // "contains" renvoie vrai si et seulement si un nœud existe et que ce nœud 
        // indique l'accumulation  de caractères qui y ont conduit  représentent
        // un mot. Elle s'appuie sur "find_node".
        bool contains(const std::string& word) const;

        // "contains_prefix" renvoie true si et seulement si un nœud existe au nom
        // de la chaîne fournie. elle s'appuie églement sur "find_node"
        bool contains_prefix(const std::string& prefix) const;

        // "loadFromFile" permet de charger à partir d'un fichier tous les mots du
        // lexique
        std::vector<std::string> load_from_file();

        void download_lexicon();
        
        // "size" renvoie le nombre de mots présents dans le lexique, elle calcule
        //  récursivement le nombre de mot dans le lexique.
        unsigned int size() const;

        //le nombre de mots dans le lexique incrémenté à l'ajout d'un nouveau mot
        unsigned int length;

        // la racine qui correspond à la chaine vide
        Node *root;   

    private:

        // "find_node" et "ensure_node_exists" font l'araignée rampant dans l'arbre

        // "find_node" renvoie le noeud qui represente la dernère lettre du mot.
        const Node *find_node(const std::string& str) const;

        // "ensure_node_exists" garantir l'existence du parcours, c'est à dire que pour
        // chaque lettre du mot, on avance le long de l'arête et on crée les arête qui
        // ne le sont pas. Elle permet de garantir qu'en avançant chaque noeud de la
        // séquence de caractères fournie existe
        Node *ensure_node_exists(const std::string& str);
};