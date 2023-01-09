// C++ code to implement the approach

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

// Preorder Traversal
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;

    // Visit Node
    cout << node->data << " ";

    // Traverse left subtree
    printPreOrder(node->left);

    // Traverse right subtree
    printPreOrder(node->right);
}