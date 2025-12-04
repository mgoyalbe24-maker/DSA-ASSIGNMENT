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

    // Insert at end
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

bool isCircular(CLL::Node* head) {
    if (!head) return true;

    CLL::Node* t = head->next;

    while (t && t != head)
        t = t->next;

    return (t == head);
}

int main() {
    CLL list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    if (isCircular(list.head))
        cout << "The list is circular.\n";
    else
        cout << "The list is NOT circular.\n";

    return 0;
}
