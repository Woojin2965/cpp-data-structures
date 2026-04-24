#include <iostream>
using namespace std;

class HashSpace{
    public:
        int key;
        int value;
        int flag;

        HashSpace() {
            this->flag = 0;
        }
};

class HashTable{
    public:
        int size = 0;
        int capacity;
        HashSpace* table;

    HashTable(int capacity) {
        this-> capacity = capacity;
        this->table = new HashSpace[capacity];
    }

    int HashFunc(int key){
        return key % capacity;
    }

    int Probing(int HashValue, int Collision){
        return (HashValue + Collision*Collision)%capacity;
    }

    void Add(int addKey, int addValue){
        if (size >= capacity*0.75){
            Resize();
        }

        int HashValue = this->HashFunc(addKey);
        int collision = 0;
        int idx = HashValue;

        
        while (table[idx].flag == 1 && table[idx].key != addKey){
            collision++;
            idx = this->Probing(HashValue, collision);
        }

        //table[idx].flag == 0 || table[idx].flag == 2
        if (table[idx].flag != 1){
            size++;
        }

        table[idx].key = addKey;
        table[idx].value = addValue;
        table[idx].flag = 1;
    }

    void Resize() {
        int initCapacity = capacity;
        HashSpace* initTable = table;

        capacity = capacity*2;
        table = new HashSpace[capacity];
        size = 0;

        for (int i=0; i<initCapacity; i++){
            if (initTable[i].flag == 1){
                Add(initTable[i].key, initTable[i].value);
            }
        }
        delete[] initTable;
    }

    int Search(int searchKey) {
        int HashValue = this->HashFunc(searchKey);
        int collision = 0;
        int idx = HashValue;

        while (table[idx].flag != 0){
            if (table[idx].key == searchKey){
                return table[idx].value;
            } 

        collision++;
        idx = this->Probing(HashValue, collision);
        }
        return NULL;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main(){
    HashTable myTable(4);
    myTable.Add(10, 100);
    myTable.Add(20, 200);
    
    cout << myTable.Search(10) << "\n";

    return 0;
}