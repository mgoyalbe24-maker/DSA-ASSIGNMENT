#include <iostream>
using namespace std;

// ================= DOUBLY LINKED LIST =================
class DLL {
public:
    struct Node {
        int data;
        Node *prev, *next;
        Node(int d) : data(d), prev(NULL), next(NULL) {}
    };
    Node *head = NULL;

    void insertFront(int x) {
        Node *n = new Node(x);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertEnd(int x) {
        Node *n = new Node(x);
        if (!head) { head = n; return; }
        Node *t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void insertAfter(int key, int x) {
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) { cout << "Key not found\n"; return; }

        Node *n = new Node(x);
        n->next = t->next;
        n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }

    void deleteNode(int key) {
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;

        if (t == head) head = head->next;
        if (t->next) t->next->prev = t->prev;
        if (t->prev) t->prev->next = t->next;
        delete t;
    }

    bool search(int key) {
        Node *t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        Node *t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

// ================= CIRCULAR LINKED LIST =================
class CLL {
public:
    struct Node {
        int data;
        Node *next;
        Node(int d) : data(d), next(NULL) {}
    };
    Node *head = NULL;

    void insertEnd(int x) {
        Node *n = new Node(x);
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node *t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *t = head, *prev = NULL;

        if (head->data == key) {
            while (t->next != head) t = t->next;
            if (head == t) { delete head; head = NULL; return; }
            t->next = head->next;
            delete head;
            head = t->next;
            return;
        }

        do {
            prev = t;
            t = t->next;
        } while (t != head && t->data != key);

        if (t->data == key) {
            prev->next = t->next;
            delete t;
        }
    }

    bool search(int key) {
        if (!head) return false;
        Node *t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void display() {
        if (!head) return;
        Node *t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    DLL dll;
    CLL cll;

    // You can test operations here manually

    return 0;
}