#include <iostream>
using namespace std;

class CLL {
public:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* head = nullptr;

    void insert(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head)
            t = t->next;

        t->next = n;
        n->next = head;
    }
};

void displayWithRepeat(CLL::Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    CLL::Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);

    cout << head->data << endl; // repeat head
}

int main() {
    CLL list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    displayWithRepeat(list.head);
    return 0;
}
