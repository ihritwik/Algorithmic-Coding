#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> temp;
        vector<int> response;
        TreeNode* curr = root;
        while((curr!=NULL) || (!temp.empty()))
        {
            while (curr!=NULL)
            {
                temp.push(curr);
                curr=curr->left;
            }
            curr = temp.top();
            temp.pop();
            response.push_back(curr->val);
            curr = curr->right;

        }
        return response;
    }
};