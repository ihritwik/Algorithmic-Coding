/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int max_dist = 0;
    // Function to return the diameter of a Binary Tree.
    int height(Node* root)
        {
            //int max_dist = 0;
            if (root==NULL) return 0;
            int left_h = height(root->left);
            int right_h = height(root->right);
            //int hei = 1+max(height(root->left),height(root->right));
            max_dist = max(max_dist,1+left_h+right_h);
            return 1+max(left_h,right_h);
        }
    int diameter(Node* root) 
    {
        // Your code here
        height(root);
        return max_dist;
    }
};