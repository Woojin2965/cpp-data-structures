#include <iostream>
using namespace std;

/*
Insert / Search value -> Node 
Iterative로 연습
Remove #4로 짜기 
*/ 

class Node{  
    public:
    int value;
    Node* parent;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node* root = NULL;

    // insert: iValue =>  void
    void insert(int iValue){
        if (root == NULL){
            root = new Node(iValue);
            return;
        }

        Node* temp = root;
        while(true){
            if (iValue < temp->value){
                if(temp->left == NULL){
                    temp->left = new Node(iValue);
                    temp->left->parent = temp;
                    return;
                }
                temp = temp->left;
            }

            else if (iValue > temp->value){
                if(temp->right == NULL){
                    temp->right = new Node(iValue);
                    temp->right->parent = temp;
                    return;
                }
                temp = temp->right;
            }

            // iValue == temp->value
            else{
                return;
            }
        }
    }


    // contains: sValue => bool
    /*
    1. root이 NULL인 경우 
    2. root->value == sValue인 경우
    3. sValue < root->value인 경우 
    4. sValue > root->value인 경우
    */
    bool contains(int sValue){
        Node* temp = root;

        while (temp != NULL){
            if (sValue == temp->value){
                return true;
            }
            else if (sValue < temp->value){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        // temp == NULL
        return false;
    }

    // remove: rValue => void
    /*
    1. No child
    2. Only right subtree
    3. Only left subtree
    4. Has both subtrees
    */
    void remove(int rValue){
        Node* max = root;
    }

};