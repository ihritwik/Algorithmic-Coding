#include <algorithm>
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
    vector<int> inorder(TreeNode* root, vector<int> &elements)
    {
        if (root==NULL) return elements;
        inorder(root->left, elements);
        elements.push_back(root->val);
        //cout<<" "<<root->val<<" ";
        inorder(root->right, elements);
        return elements;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> data, response;
        bool answer = false;
        // inorder traversal to get a sorted list
        response = inorder(root, data);
        auto it_front = 0;
        auto it_back = response.size()-1;
        while(it_front<it_back){
            if ((response[it_front] + response[it_back])==k){
                answer = true;
                break;
            }
            else if ((response[it_front] + response[it_back])>k){
                it_back--;
            }
            else {
                it_front++;
            }
        }
        return answer;
    }
};

