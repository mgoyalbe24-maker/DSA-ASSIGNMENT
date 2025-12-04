#include <iostream>

using namespace std;
#define SIZE 100
class Stack
{
    int arr[SIZE];
    int top;

public:
    Stack() { top = -1; }
    void push(int val)
    {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = val;
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow\n";
        else
            top--;
    }
    void peek()
    {
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << arr[top] << endl;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == SIZE - 1;
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    Stack s;
    int choice, val;
    do
    {
        cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.isEmpty\n6.isFull\n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << (s.isEmpty() ? "Empty\n" : "Not Empty\n");
            break;
        case 6:
            cout << (s.isFull() ? "Full\n" : "Not Full\n");
            break;
        }
    } while (choice != 7);
    return 0;
}