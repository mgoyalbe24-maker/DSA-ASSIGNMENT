#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void deleteOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                count++;
            } else curr = curr->next;
        }
        cout << "Occurrences deleted: " << count << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int n, val, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }
    cout << "Enter key to delete: ";
    cin >> key;
    list.deleteOccurrences(key);
    cout << "List after deletion: ";
    list.display();
}