#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue
{
    queue<int> q;

public:
    // Push element into the stack
    void push(int x)
    {
        int sz = q.size();
        q.push(x);

        // Rotate the old elements to the back
        for (int i = 0; i < sz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop element from the stack
    void pop()
    {
        if (!q.empty())
        {
            cout << "Popped: " << q.front() << endl;
            q.pop();
        }
        else
        {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    // Return top element
    int top()
    {
        if (!q.empty())
            return q.front();

        cout << "Stack is empty!\n";
        return -1; // default value
    }

    // Check if stack is empty
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    StackOneQueue st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop();
    cout << "Top after pop: " << st.top() << endl;

    st.pop();
    st.pop();
    st.pop(); // extra pop to show empty handling

    return 0;
}
