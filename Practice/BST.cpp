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

    // remove: rValue => bool
    /*
    1. No child
    2. Only right subtree
    3. Only left subtree
    4. Has both subtrees
    */
    bool remove(int target){
        Node* temp = root;
        if (root == NULL){
            return false;
        }
        
        // find target
        while (temp != NULL && temp->value != target){
            if (target > temp->value){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }

        if (temp == NULL){
            return false;
        }

        // find replace
        // case 4 will be included in case 2,3
        if (temp->right != NULL && temp->left != NULL){
            Node* replace = temp->right;
            while (replace->left != NULL){
                replace = replace->left;
            }

            temp->value = replace->value;
            temp = replace;
        }
        
        // case 1
        // left에 Null값 업데이트하기 (segmentation error 방지)
        if (temp->right == NULL && temp->left == NULL){
            if(temp->parent == NULL){
                root = NULL;
            }
            else if (temp == temp->parent->left){
                temp->parent->left = NULL;
            }else{
                temp->parent->right = NULL;
            }
        }
        
        // case 2,3
        else{
            Node* child = NULL;
            if(temp->left != NULL){
                child = temp->left;
            }else{
                child = temp->right;
            }

            child->parent = temp->parent;

            if(temp->parent == NULL){
                root = child;
            }
            else if (temp == temp->parent->left){
                temp->parent->left = child;
            }else{
                temp->parent->right = child;
            }
        }

        delete temp;
        return true;
    }

    void preorder(Node* root = NULL){
        Node* temp = root;
        if (temp = NULL){
            return;
        }
        cout << temp->value << " " << "\n";
        preorder(temp->left);
        preorder(temp->right);
    }
};