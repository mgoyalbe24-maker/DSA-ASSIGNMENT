#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertSpecific(int key, int val, bool after) {
        if (!head) { cout << "List empty.\n"; return; }
        Node* temp = head;
        if (!after && temp->data == key) { insertAtBeginning(val); return; }
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found.\n"; return; }
        Node* newNode = new Node{val, NULL};
        if (after) { newNode->next = temp->next; temp->next = newNode; }
        else {
            Node* prev = head;
            while (prev->next != temp) prev = prev->next;
            prev->next = newNode;
            newNode->next = temp;
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecific(int key) {
        if (!head) return;
        if (head->data == key) { deleteFromBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) { cout << "Node not found.\n"; return; }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) { cout << "Found at position " << pos << endl; return; }
            temp = temp->next;
            pos++;
        }
        cout << "Not found.\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) { cout << "List empty.\n"; return; }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key; bool after;

    do {
        cout << "\n1.Insert Begin  2.Insert End  3.Insert Before/After\n"
             << "4.Delete Begin  5.Delete End  6.Delete Specific\n"
             << "7.Search        8.Display     0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter key: "; cin >> key;
                    cout << "Enter new value: "; cin >> val;
                    cout << "After(1) or Before(0)? "; cin >> after;
                    list.insertSpecific(key, val, after); break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: cout << "Enter value to delete: "; cin >> key; list.deleteSpecific(key); break;
            case 7: cout << "Enter value to search: "; cin >> key; list.search(key); break;
            case 8: list.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}