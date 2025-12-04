#include <iostream>
using namespace std;

//// =========================================
////      DOUBLY LINKED LIST (DLL)
//// =========================================

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

// Count size of DLL
int sizeDLL(DLL::Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

// Display DLL
void displayDLL(DLL::Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


//// =========================================
////      CIRCULAR LINKED LIST (CLL)
//// =========================================

class CLL {
public:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* head = nullptr;

    // Insert at end for CLL
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

// Count size of CLL
int sizeCLL(CLL::Node* head) {
    if (!head) return 0;

    int c = 0;
    CLL::Node* t = head;

    do {
        c++;
        t = t->next;
    } while (t != head);

    return c;
}

// Display CLL (one cycle)
void displayCLL(CLL::Node* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }

    CLL::Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);

    cout << endl;
}


//// =========================================
////                MAIN
//// =========================================

int main() {

    //// ----- TEST DLL -----
    DLL dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    cout << "DLL elements: ";
    displayDLL(dll.head);

    cout << "DLL size = " << sizeDLL(dll.head) << endl << endl;


    //// ----- TEST CLL -----
    CLL cll;
    cll.insert(5);
    cll.insert(15);
    cll.insert(25);

    cout << "CLL elements: ";
    displayCLL(cll.head);

    cout << "CLL size = " << sizeCLL(cll.head) << endl;

    return 0;
}
