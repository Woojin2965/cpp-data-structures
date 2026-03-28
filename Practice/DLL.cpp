#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

    Node(int value){
        this->value = value;
    }
};

class DLL {
    public:
        int size = 0;
        Node* head = NULL;
        Node* tail = NULL;

    void Add(int addingValue) {
        Node* n = new Node(addingValue);
        n -> next = NULL;
        n -> prev = NULL;

        if (head == NULL) {
            head = n;
            tail = n;
        }
        else{
            n -> prev = tail;
            tail -> next = n;
            tail = n;
        }
        size ++;
    }

    bool Remove(int removingValue) {
        if (head == NULL) {
            return false;
        }

        if (removingValue == head -> value) {
            if (head == tail) {
                head == NULL;
                tail == NULL;
            }
            else{
                head = head -> next;
                head -> prev = NULL;
            }
            size --;
            return true;
        }

        Node* n = head -> next;
        while (n != NULL && removingValue != n -> value) {
            n = n -> next;
        }

        if (n == tail) {
            tail = tail -> prev;
            tail -> next = NULL;
            size --;
            return true;
        }
        else if (n != NULL) {
            n -> prev -> next = n -> next;
            n -> next -> prev = n -> prev;
            size --;
            return true;
        }
        return false;
    }
};