#include <iostream>
#define MAX 5
using namespace std;
class CircularQueue {
int arr[MAX];
int front, rear;
public:
CircularQueue() {
front = -1;
rear = -1;
}
bool isEmpty() {
return (front == -1);
}
bool isFull() {
return ((rear + 1) % MAX == front);
}
void enqueue(int x) {
if (isFull()) {
cout << "Queue is FULL\n";
return;
}
if (isEmpty()) {
front = rear = 0;
} else {
rear = (rear + 1) % MAX;
}

arr[rear] = x;
cout << x << " enqueued\n";
}
void dequeue() {
if (isEmpty()) {
cout << "Queue is EMPTY\n";
return;
}
cout << "Dequeued: " << arr[front] << endl;
if (front == rear) {
front = rear = -1; // reset when last element removed
} else {
front = (front + 1) % MAX;
}
}
void peek() {
if (isEmpty()) cout << "Queue is EMPTY\n";
else cout << "Front element: " << arr[front] << endl;
}
void display() {
if (isEmpty()) {
cout << "Queue is EMPTY\n";
return;
}
cout << "Queue elements: ";
int i = front;
while (true) {
cout << arr[i] << " ";
if (i == rear) break;
i = (i + 1) % MAX;
}
cout << endl;
}
};
int main() {
CircularQueue cq;
int choice, val;
do {
cout << "\n=== Circular Queue Menu ===\n";

cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value: ";
cin >> val;
cq.enqueue(val);
break;
case 2:
cq.dequeue();
break;
case 3:
cq.peek();
break;
case 4:
cq.display();
break;
case 5:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice!\n";
}
} while (choice != 5);
return 0;
}