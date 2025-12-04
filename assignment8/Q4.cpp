#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1e9, 1e9);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    if (isBST(root)) cout << "It is a BST";
    else cout << "Not a BST";
}