#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

// Inorder Traversal
void printInorder(Node* node)
{
    if (node == NULL)
        return;

    // Traverse left subtree
    printInorder(node->left);

    // Visit node
    cout << node->data << " ";

    // Traverse right subtree
    printInorder(node->right);
}
