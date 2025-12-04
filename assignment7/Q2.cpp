#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIdx = left;
        int maxIdx = right;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }

        swap(a[left], a[minIdx]);

        // If max index was at left, fix it
        if (maxIdx == left)
            maxIdx = minIdx;

        swap(a[right], a[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}