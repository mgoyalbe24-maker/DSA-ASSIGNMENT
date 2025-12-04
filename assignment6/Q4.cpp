#include <iostream>
using namespace std;

class DLL {
public:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;

    // Insert at end
    void insert(int x) {
        Node* n = new Node(x);

        if (!head) {
            head = n;
            return;
        }

        Node* t = head;
        while (t->next)
            t = t->next;

        t->next = n;
        n->prev = t;
    }
};

void displayDLL(DLL::Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool isPalindromeDLL(DLL::Node* head) {
    if (!head) return true;

    DLL::Node *l = head, *r = head;

    // Move r to last node
    while (r->next)
        r = r->next;

    // Compare from both sides
    while (l != r && r->next != l) {
        if (l->data != r->data)
            return false;
        l = l->next;
        r = r->prev;
    }

    return true;
}

int main() {
    DLL dll;

    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(2);
    dll.insert(1);

    cout << "DLL: ";
    displayDLL(dll.head);

    if (isPalindromeDLL(dll.head))
        cout << "The DLL is a palindrome.\n";
    else
        cout << "The DLL is NOT a palindrome.\n";

    return 0;
}
