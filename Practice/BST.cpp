#include <iostream>
using namespace std;

/*
Insert / Search value -> Node 
Iterative로 연습
Remove #4로 짜기 
*/ 

template <typename T>
class Node{  
    public:
    T value;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    Node(T value){
        this->value = value;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BST{
    public:
    Node<T>* root = NULL;

    // insert: iValue =>  void
    void insert(T iValue){
        if (root == NULL){
            root = new Node<T>(iValue);
            return;
        }

        Node<T>* temp = root;
        while(true){
            if (iValue < temp->value){
                if(temp->left == NULL){
                    temp->left = new Node<T>(iValue);
                    temp->left->parent = temp;
                    return;
                }
                temp = temp->left;
            }

            else if (iValue > temp->value){
                if(temp->right == NULL){
                    temp->right = new Node<T>(iValue);
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
    bool contains(T sValue){
        Node<T>* temp = root;

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
    bool remove(T target){
        Node<T>* temp = root;
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
            Node<T>* replace = temp->right;
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
            Node<T>* child = NULL;
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

    // tree.preorder(tree.root) 로 부르기
    void preorder(Node<T>* root = NULL){
        Node<T>* temp = root;
        if (temp == NULL){ // = 로 써서 NULL에서 터졌었음
            return;
        }
        cout << temp->value << " " << "\n";
        preorder(temp->left);
        preorder(temp->right);
    }
};

int main(){
    BST<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.remove(5);
    tree.preorder(tree.root);           // 8 3
    cout << tree.contains(3) << "\n";  // 1
    return 0;
}
