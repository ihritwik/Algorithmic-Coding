// Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* prev = NULL;
    Node * bToDLL(Node *root)
    {
        // your code here
        if (root==NULL) return root;
        Node* head = bToDLL(root->left);
        if (prev==NULL) {head=root;}
        else{
            root->left=prev;
            prev->right = root;
        }
        prev=root;
        bToDLL(root->right);
        return head;
    }
};
