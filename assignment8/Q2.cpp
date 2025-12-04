#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

// INSERT
Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

// SEARCH (Recursive)
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// SEARCH (Non-Recursive)
Node* searchIter(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// MINIMUM
Node* minValue(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// MAXIMUM
Node* maxValue(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// INORDER SUCCESSOR
Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minValue(x->right);

    Node* succ = NULL;
    while (root) {
        if (x->data < root->data)
            succ = root, root = root->left;
        else if (x->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

// INORDER PREDECESSOR
Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maxValue(x->left);

    Node* pred = NULL;
    while (root) {
        if (x->data > root->data)
            pred = root, root = root->right;
        else if (x->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);

    Node* x = searchRec(root, 30);

    cout << "Min: " << minValue(root)->data << endl;
    cout << "Max: " << maxValue(root)->data << endl;

    cout << "Successor of 30: " << inorderSuccessor(root, x)->data << endl;
    cout << "Predecessor of 30: " << inorderPredecessor(root, x)->data << endl;
}