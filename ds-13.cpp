#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }
    
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteNode() {
        if (heap.size() == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Heap h;
    h.insert(10);
    h.insert(30);
    h.insert(20);
    h.insert(5);
    h.insert(40);

    cout << "Heap elements after insertion: ";
    h.display();

    h.deleteNode();
    cout << "Heap elements after deletion: ";
    h.display();

    return 0;
}
