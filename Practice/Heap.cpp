#include <iostream>
using namespace std;
#include <stdexcept>

class MaxHeap{
    public:
        int capacity;
        int size;
        int* arr;

    MaxHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }
    ~MaxHeap(){
        delete[] arr;
    }

    int getParent(int i) {
        return (i-1) / 2;
    }

    int getLeft(int i){
        return (i*2) + 1;
    }

    int getRight(int i){
        return (i*2) + 2;
    }

    void swap(int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void insert(int iValue){
        if (size == capacity){
            return;
            // Update here w/ stdexept later
        }

        arr[size] = iValue;
        
        while (size > 0){
            int parent = getParent(size);
            if(arr[size] > arr[parent]){
                swap(size, parent);
                size = parent;
            }else{
                break;
            }
        }

        size ++;
    }

    int pop(){
        if (size == 0){
            return;
            // Update here w/ stdexept later
        }

        int maxValue = arr[0];
        arr[0] = arr[size - 1];
        size--;

        int temp = 0;
        while (size != 0){
            int left = getLeft(temp);
            int right = getRight(temp);

            if (left >= size){
                break;
            }

            int max = left;
            if (right < size && arr[right] > arr[left]){
                max = right;
            }

            if (arr[max] > arr[temp]){
                swap(temp, max);
                temp = max;
            }else{
                break;
            }
            return maxValue;
        }
    }
};

int main(){
    MaxHeap myHeap(5);
    myHeap.insert(1);
    myHeap.insert(2);
    myHeap.insert(3);
    myHeap.pop();

    for (int i = 0; i < myHeap.size; i++){
        cout << myHeap.arr[i] << " ";
    }
    cout << "\n";
    return 0;
}