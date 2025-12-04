#include <iostream>
#define MAX 5
using namespace std;
class Queue {
int arr[MAX], front, rear;
public:
Queue() { front = -1; rear = -1; }
bool isEmpty() { return front == -1; }
bool isFull() { return (rear + 1) % MAX == front; }
void enqueue(int x) {
if (isFull()) { cout << "Queue Full\n"; return; }
if (isEmpty()) front = 0;
rear = (rear + 1) % MAX;
arr[rear] = x;
}
void dequeue() {
if (isEmpty()) { cout << "Queue Empty\n"; return; }
cout << "Dequeued: " << arr[front] << endl;
if (front == rear) front = rear = -1;
else front = (front + 1) % MAX;
}
void peek() {
if (!isEmpty()) cout << "Front: " << arr[front] << endl;
else cout << "Queue Empty\n";
}
void display() {
if (isEmpty()) { cout << "Queue Empty\n"; return; }
cout << "Queue: ";
for (int i = front; i != rear; i = (i + 1) % MAX) cout << arr[i] << " ";
cout << arr[rear] << endl;
}
};
int main() {
Queue q;
int choice, val;
do {

cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\nChoice: ";
cin >> choice;
switch (choice) {
case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
case 2: q.dequeue(); break;
case 3: q.display(); break;
case 4: q.peek(); break;
}
} while (choice != 5);
return 0;
}