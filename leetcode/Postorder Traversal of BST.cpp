// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class to define structure of a node
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

// PostOrder Traversal
void printPostOrder(Node* node)
{
    if (node == NULL)
        return;

    // Traverse left subtree
    printPostOrder(node->left);

    // Traverse right subtree
    printPostOrder(node->right);

    // Visit node
    cout << node->data << " ";
}
