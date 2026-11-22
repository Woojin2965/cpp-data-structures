#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T value;
        Node<T>* next; // Node라는 데이터타입?

    Node(T value){
        this->value = value;
        this->next = NULL; // 안 넣으면 쓰레기 값 -> Contains에서 터짐
    }
};

template <typename T>
class SLL {
    public:
        int size = 0;
        Node<T>* head = NULL;
        Node<T>* tail = NULL;

    // tail 다음에 새 노드 추가하고 tail 업데이트
    void Add(T addingValue) {
        Node<T>* n = new Node<T>(addingValue);
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
    bool Contains(T wantedValue) {
        Node<T>* n = head;
        while (n != NULL && n -> value != wantedValue) {
            n = n -> next;
        }
        if (n == NULL) {
            return false;
        }
        return true; // return (n != NULL)
    }

    // void로 짜고싶어요! -> except throw로 에러처리를 하면 됨 (return false)
    // 지워지면 true 아니면 false
    // 책에서 except로 thorw안하는 이유? -> 다른 언어엔 없어서?
    // 메모리? -> 떼어낸 노드를 delete 안 해서 새는 중. 나중에 고치기
    bool Remove(T removingValue) {
        if (head == NULL) {
            return false;
        }
        Node<T>* n = head;
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
    // 단순 cout? -> 일단 cout으로
    void Print() {
        Node<T>* n = head;
        while (n != NULL) {
            cout << n -> value << " ";
            n = n -> next;
        }
        cout << "\n";
    }
};

int main(){
    SLL<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Remove(2);
    list.Print();                       // 1 3
    cout << list.Contains(3) << "\n";  // 1
    return 0;
}
