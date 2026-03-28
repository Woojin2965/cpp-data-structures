#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next; // Node라는 데이터타입?

    Node(int value){
        this->value = value;
    }
};

class SLL {
    public:
        int size = 0;
        Node* head = NULL;
        Node* tail = NULL;

    // tail 다음에 새 노드 추가하고 tail 업데이트
    void Add(int addingValue) {
        Node* n = new Node(addingValue);
        if (head == NULL) {
            head = n;
            tail = n;
        }
        else{
            tail -> next = n; // (*tail).next = n
            tail = n;
        }
        size ++;
    }

    // 첫 노드부터 끝까지 검사
    bool Contains(int wantedValue) {
        Node* n = head;
        while (n != NULL && n->value != wantedValue) {
            n = n->next;
        }
        if (n == NULL) {
            return false;
        }
        return true; // return (n != NULL)
    }

    // void로 짜고싶어요! -> except throw로 에러처리를 하면 됨 (return false)
    // 지워지면 true 아니면 false
    // 책에서 except로 thorw안하는 이유? -> 다른 언어엔 없어서?
    // 메모리?
    bool Remove(int removingValue) {
        if (head == NULL) {
            return false;
        }
        Node* n = head;
        if (n -> value == removingValue) {
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else{
                head = head -> next;
            }
            size --;
            return true;
        }
        while (n -> next != NULL && n -> next -> value != removingValue) {
            n = n -> next;
        }
        if (n -> next != NULL) {
            if (n -> next == tail) {
                tail = n;
            }
            n -> next = n -> next -> next;
            size --;
            return true;
        }
        return false;
    }

    // traversal -> yield??
    // 단순 cout?
};