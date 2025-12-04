#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i != 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i+1, r = 2*i+2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }

    int pop() {
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(50);
    pq.push(20);
    pq.push(90);
    pq.push(60);

    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
}