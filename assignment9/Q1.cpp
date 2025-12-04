#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool increasing) {
    int e = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (increasing) {
        if (l < n && a[l] > a[e]) e = l;
        if (r < n && a[r] > a[e]) e = r;
    } else {
        if (l < n && a[l] < a[e]) e = l;
        if (r < n && a[r] < a[e]) e = r;
    }

    if (e != i) {
        swap(a[i], a[e]);
        heapify(a, n, e, increasing);
    }
}

void heapSort(int a[], int n, bool increasing) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, increasing);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, increasing);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int choice;
    cin >> choice;

    heapSort(a, n, choice == 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}