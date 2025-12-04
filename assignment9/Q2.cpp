#include <iostream>
using namespace std;

class PriorityQueue {
    int a[1000];
    int n;

    void heapifyUp(int i) {
        while (i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i) {
        int l, r, e;
        while (true) {
            l = 2*i + 1;
            r = 2*i + 2;
            e = i;

            if (l < n && a[l] > a[e]) e = l;
            if (r < n && a[r] > a[e]) e = r;

            if (e == i) break;
            swap(a[i], a[e]);
            i = e;
        }
    }

public:
    PriorityQueue() { n = 0; }

    void push(int x) {
        a[n] = x;
        heapifyUp(n);
        n++;
    }

    int top() {
        return n == 0 ? -1 : a[0];
    }

    void pop() {
        if (n == 0) return;
        a[0] = a[n-1];
        n--;
        heapifyDown(0);
    }

    bool empty() {
        return n == 0;
    }
};

int main() {
    PriorityQueue pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}