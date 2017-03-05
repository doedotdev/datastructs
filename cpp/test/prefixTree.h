//
// Created by Benjamin D. Horn on 3/2/17.
//

#ifndef DATASTRUCTS_PREFIXTREE_H
#define DATASTRUCTS_PREFIXTREE_H


#include <string>
#include <vector>

using namespace std;

const unsigned int B_FACTOR = 27;  // a..z plus space all toLower

struct tree_node_struct{
    bool word;
    tree_node_struct* links[B_FACTOR];
};

class prefixTree{

public:

    // const
    prefixTree(){
        root_tree_node = new tree_node_struct;
        setLinks(root_tree_node);
        count_tree_nodes = 1;
        count_tree_strings = 0;
    }

    //copy const
    prefixTree(const prefixTree &copy){
        root_tree_node = new tree_node_struct;
        setLinks(root_tree_node);
        fullCopy(root_tree_node, copy.root_tree_node);
        count_tree_nodes = copy.count_tree_nodes;
        count_tree_strings = copy.count_tree_strings;
    }

    //assignment
    prefixTree& operator=(const prefixTree& other){
        if(this == &other){
            return *this;
        }
        clear(root_tree_node);
        for(unsigned int i = 0; i < 27; i++){
            root_tree_node->links[i] = NULL;
        }
        fullCopy(root_tree_node, other.root_tree_node);
        count_tree_nodes = other.count_tree_nodes;
        count_tree_strings = other.count_tree_strings;
        return *this;
    }

    // Initializes pointers to NULL because c++ can't do it itself.
    void setLinks(tree_node_struct* node){
        for(unsigned int i = 0; i < 27; i++){
            node->links[i] = NULL;
        }
    }
// fill me in!
// Converts string to lowercase
    string lower(string thing){
        string ret = "";
        for(unsigned int i = 0; i < thing.length(); i++){
            if(thing[i] >= 'A' && thing[i] <= 'Z'){
                ret += (thing[i] - 'A' + 'a');
            }
            else if(isalpha(thing[i]) == false){
                ret += ' ';
            }
            else{
                ret += thing[i];
            }
        }
        return ret;
    }


    //dest
    ~prefixTree(){
        this->clear(root_tree_node);
        delete root_tree_node;
        root_tree_node = NULL;
    }

   // number of nodes fast
    unsigned int sizeN(){
        return count_tree_nodes;
    }

    // number of strings fast
    unsigned int sizeS(){
        return count_tree_strings;
    }

    // insert a thing
    bool insert(string thing){
        string lowered = lower(thing);
        return insert(lowered, root_tree_node);
    }

    // returns height of the preTree
    int getHeight(){
        return getHeight(root_tree_node) - 2;
    }

    int getNumNodes(){
        return getNumNodes(root_tree_node);
    }

    int getNumStored(){
        return getNumStored(root_tree_node);
    }

    vector<string> getWPrefix(string prefix){
        vector<string> ret;
        tree_node_struct* node = root_tree_node;
        string orig_prefix = prefix;
        while(prefix.length() > 0){
            if(node == NULL){
                return ret;
            }
            node = node->links[charIndex(prefix[0])];
            prefix = prefix.substr(1,prefix.length()-1);
        }
        getAllStored(node, "", ret);
        vector<string> ret2;
        for(unsigned int i = 0; i < ret.size(); i++){
            ret2.push_back(orig_prefix + ret[i]);
        }
        return ret2;
    }

    vector<string> getAllStored(){
        vector<string> ret;
        getAllStored(root_tree_node, "", ret);
        return ret;
    }

    int getNumWPrefix(string prefix){
        vector<string> stored = this->getWPrefix(prefix);
        return stored.size();
    }

    bool isStored(string thing){
        return isStored(thing, root_tree_node);
    }


private:
    //recursive functions are below here

    tree_node_struct *root_tree_node; // root node
    unsigned int count_tree_nodes;
    unsigned int count_tree_strings;

    int charIndex(char letter){
        if(letter == ' '){
            return 26;
        }
        return letter - 'a';
    }

    bool insert(string thing, tree_node_struct* node){
        int len = thing.length();
        if(len != 0){
            if(node->links[charIndex(thing[0])] == NULL){
                tree_node_struct* new_node1 = new tree_node_struct;
                setLinks(new_node1);
                count_tree_nodes++;
                new_node1->word = false;
                node->links[charIndex(thing[0])] = new_node1;
            }
            return insert(thing.substr(1,len-1), node->links[charIndex(thing[0])]);
        }
        else{
            if(node->word == true){
                return true;
            }
            node->word = true;
            count_tree_strings++;
            return false;
        }
    }


    int getHeight(tree_node_struct* node){
        if(node == NULL){
            return 1;
        }
        else{
            unsigned int max_height = 0;
            for(unsigned int i = 0; i < 27; i++){
                unsigned int ht = getHeight(node->links[i]);
                if(ht > max_height){
                    max_height = ht;
                }
            }
            return max_height + 1;
        }
    }


    int getNumNodes(tree_node_struct* node){
        if(node == NULL){
            return 0;
        }
        else{
            unsigned int num_nodes = 0;
            for(unsigned int i = 0; i < 27; i++){
                unsigned int ht = getNumNodes(node->links[i]);
                num_nodes += ht;
            }
            return num_nodes + 1;
        }
    }

    int getNumStored(tree_node_struct* node){
        unsigned int num_words = 0;
        for(unsigned int i = 0; i < 27; i++){
            tree_node_struct* other = node->links[i];
            if(other != NULL){
                if(other->word == true){
                    num_words++;
                }
                num_words += getNumStored(other);

            }
        }
        return num_words;
    }

    void getAllStored(tree_node_struct* node, string words, vector<string> &all_words){
        if(node == NULL){
            return;
        }
        else{
            for(unsigned int i = 0; i < 27; i++){
                tree_node_struct* other = node->links[i];
                string current_word = words;
                if(other != NULL){
                    current_word += (char)(i + 'a');
                    if(other->word == true){
                        all_words.push_back(current_word);
                    }
                    getAllStored(other, current_word, all_words);
                }
            }
        }
    }


    bool isStored(string thing, tree_node_struct* node){
        if(node == NULL){
            return false;
        }
        if(thing.length() == 0){
            if(node->word == true){
                return true;
            }
            else{
                return false;
            }
        }
        return isStored(thing.substr(1), node->links[charIndex(thing[0])]);
    }

    void fullCopy(tree_node_struct* node, tree_node_struct* other_node){
        node->word = other_node->word;
        for(unsigned int i = 0; i < 27; i++){
            if(other_node->links[i] != NULL){
                tree_node_struct* new_node = new tree_node_struct;
                setLinks(new_node);
                node->links[i] = new_node;
                fullCopy(new_node, other_node->links[i]);
            }
        }
    }
    void clear(tree_node_struct* node){
        for(unsigned int i = 0; i < 27; i++){
            if(node->links[i] != NULL){
                clear(node->links[i]);
            }
        }
        if(node != root_tree_node){
            delete node;
            node = NULL;
        }
    }
};
#endif //DATASTRUCTS_PREFIXTREE_H
