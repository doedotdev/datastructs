//
// Created by Benjamin D. Horn on 2/24/17.
//

#ifndef DATASTRUCTS_BST_H
#define DATASTRUCTS_BST_H


#include <ostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

template <class T>
class Node{
public:
    Node(Node* left, Node* right, T value)
            :data(value),left(left),right(right){} // initializes data before body of constructor executes
    T data;
    Node* left;
    Node* right;
};

template <class T>
class bst {

public:
    // Constructor
    bst( int (*f)(const T&, const T&) ){
        cmpfn = f;
        // TODO
        root = NULL;
        ents = 0;
    }

    // Destructor
    ~bst() {
        // TODO
        clear(root);
        root = NULL;
        ents = 0;
    }

    // Copy Constructor
    bst(const bst& other){
        // TODO
        cmpfn = other.cmpfn;
        ents = other.ents;
        root = NULL;
        if(other.root != NULL){
            insertPre(other.root);
        }
    }

    // Assignment Overload
    bst<T>& operator= (const bst& other){
        // TODO
        if(this != &other){
            this->clear();
            cmpfn = other.cmpfn;
            ents = other.ents;
            root = NULL;
            if(other.root != NULL){
                insertPre(other.root);
            }
        }
        return *this;
    }

    // Inserts the thing
    void insert(T thing){
        // TODO
        ents++;
        if(!root){
            root = new Node<T>(NULL, NULL, thing);
            return;
        }
        insert(root, thing);
    }

    // Finds the thing
    bool find(const T& thing) const{
        // TODO
        return find(root, thing);
    }

    // Returns the number of nodes
    unsigned int size() const{
        // TODO
        return ents;
    }

    // Returns smallest value
    T getSmallest() const{
        // TODO
        return getSmallest(root);
    }

    // Returns largest value
    T getLargest() const{
        // TODO
        return getLargest(root);
    }

    // Clears tree
    void clear(){
        // TODO
        clear(root);
        root = NULL;
        ents = 0;
    }

    // Returns nodes in left->node->right
    string getInOrder() const{
        // TODO
        //getInOrder(root);
        return "[" + getInOrder(root) + "]";
    }

    // Returns nodes in node->left->right
    string getPreOrder() const{
        // TODO
        return "[" + getPreOrder(root) + "]";
    }

    // Returns nodes in left->right->node
    string getPostOrder() const{
        // TODO
        return "[" + getPostOrder(root) + "]";
    }

    // End Lab assignment ---------------------------------------

    // Start HW assignment --------------------------------------
    // Returns height of tree
    unsigned int getHeight() const{
        // TODO
        if(root == NULL){
            return 0;
        }
        return getHeight(root)-1;
    }

    // Returns true if tree is full, false otherwise
    bool isFull() const{
        // TODO
        return isFull(root);
    }

    // Returns true if tree is balanced, false otherwise
    bool isBalanced() const{
        // TODO
        return isBalanced(root);
    }

private:
    Node<T>* root;
    unsigned int ents;
    int (*cmpfn)(const T& left, const T& right);

    // TODO  Hint, you may have many functions down here!
    // Recursive insert
    void insert(Node<T>* node, T thing){
        if(!node){
            if(root == NULL){
                root = new Node<T>(NULL, NULL, thing);
                return;
            }
            throw logic_error("Node is null");
        }
        if((*cmpfn)(thing, node->data) <= 0){
            if(node->left){
                insert(node->left, thing);
            }
            else{
                node->left = new Node<T>(NULL, NULL, thing);
            }
        }
        else{
            if(node->right){
                insert(node->right, thing);
            }
            else{
                node->right = new Node<T>(NULL, NULL, thing);
            }
        }
    }

    // Recursive InOrder string
    string getInOrder(Node<T>* node) const{
        if(!node){
            return "";
        }
        else{
            stringstream s;
            string ret = "";
            ret = ret + getInOrder(node->left);
            s << node->data;
            if(node->data != this->getLargest()){
                ret = ret + s.str() + ",";
            }
            else{
                ret = ret + s.str();
            }
            ret = ret + getInOrder(node->right);
            return ret;
        }
    }

    // Recursive PreOrder string
    string getPreOrder(Node<T>* node) const{
        if(!node){
            return "";
        }
        else{
            stringstream s;
            string ret = "";
            s << node->data;
            if(node != root){
                ret = ret + "," + s.str();
            }
            else{
                ret = ret + s.str();
            }
            ret = ret + getPreOrder(node->left);
            ret = ret + getPreOrder(node->right);
            return ret;
        }
    }

    // Recursive PostOrder string
    string getPostOrder(Node<T>* node) const{
        if(!node){
            return "";
        }
        else{
            stringstream s;
            string ret = "";
            ret = ret + getPostOrder(node->left);
            ret = ret + getPostOrder(node->right);
            s << node->data;
            if(node != root){
                ret = ret + s.str() + ",";
            }
            else{
                ret = ret + s.str();
            }
            return ret;
        }
    }

    // Returns true if value is found
    bool find(Node<T>* node, T thing) const{
        if(!node){
            return false;
        }
        else{
            if(thing == node->data){
                return true;
            }
            if((*cmpfn)(thing, node->data) <= 0){
                if(node->left){
                    return find(node->left, thing);
                }
                else{
                    if(thing == node->data){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                if(node->right){
                    return find(node->right, thing);
                }
                else{
                    if(thing == node->data){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
    }

    // Recursively finds smallest value
    T getSmallest(Node<T>* node) const{
        if(!node){
            throw logic_error("Empty Tree");
        }
        if(!node->left){
            return node->data;
        }
        else{
            return getSmallest(node->left);
        }
    }

    // Recursively finds largest value
    T getLargest(Node<T>* node) const{
        if(!node){
            throw logic_error("Empty Tree");
        }
        if(!node->right){
            return node->data;
        }
        else{
            return getLargest(node->right);
        }
    }

    // Recursively clears
    void clear(Node<T>* node){
        if(!node){
            return;
        }
        else{
            clear(node->left);
            clear(node->right);
            delete node;
            node = NULL;
            return;
        }
    }

    // Recursively copies
    void insertPre(Node<T>* node){
        if(!node){
            return;
        }
        else{
            insert(this->root, node->data);
            insertPre(node->left);
            insertPre(node->right);
            return;
        }
    }

    // Recursively finds height
    unsigned int getHeight(Node<T>* node) const{
        if(!node){
            return 0;
        }
        else{
            unsigned int lft = getHeight(node->left);
            unsigned int rgt = getHeight(node->right);
            if(lft == 0 && rgt == 0){
                return 1;
            }
            else if(lft == rgt){
                return lft + 1;
            }
            else if(lft > rgt){
                return lft + 1;
            }
            else{
                return rgt + 1;
            }
        }
    }

    // Recursively determines if tree is full
    bool isFull(Node<T>* node) const{
        if(!node){
            return true;
        }
        if(node->left == NULL || node->right == NULL){
            unsigned int left_height = 0;
            unsigned int right_height = 0;
            adjustHeight(node, left_height, right_height);
            if(left_height == right_height){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            bool lft = isFull(node->left);
            bool rgt = isFull(node->right);
            if(lft == true && rgt == true){
                unsigned int left_height = 0;
                unsigned int right_height = 0;
                adjustHeight(node, left_height, right_height);
                if(left_height == right_height){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    void adjustHeight(Node<T>* node, unsigned int &left_height, unsigned int &right_height) const{
        if(node->left == NULL){
            left_height = getHeight(node->left);
        }
        else{
            left_height = getHeight(node->left)+1;
        }
        if(node->right == NULL){
            right_height = getHeight(node->right);
        }
        else{
            right_height = getHeight(node->right)+1;
        }
    }

    // Recursively determines if tree is balanced
    bool isBalanced(Node<T>* node) const{
        if(!node){
            return true;
        }
        if(node->left == NULL || node->right == NULL){
            unsigned int left_height = getHeight(node->left);
            unsigned int right_height = getHeight(node->right);
            if(left_height == right_height || left_height == right_height-1 || left_height == right_height+1){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            bool left_balance = isBalanced(node->left);
            bool right_balance = isBalanced(node->right);
            if(left_balance == true && right_balance == true){
                unsigned int left_height = getHeight(node->left);
                unsigned int right_height = getHeight(node->right);
                if(left_height == right_height || left_height == right_height-1 || left_height == right_height+1){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

};



#endif //DATASTRUCTS_BST_H
