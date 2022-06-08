#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<pair<int,int>> data; 
    int getHeight(TreeNode* root){
        if (root == NULL) return -1;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        int root_height = max(left_height, right_height) + 1;
        data.push_back(make_pair(root_height, root->val));
        return root_height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        vector<vector<int>> response;
        sort (data.begin(), data.end());
        int n = data.size();
        int height = 0;
        int i = 0;
        
        while (i<n){
            vector<int> set_of_leaves;
            while ((i<n) && (data[i].first == height))
            {
                set_of_leaves.push_back(data[i].second);
                i++;
            }
            response.push_back(set_of_leaves);
            height++;
        }
        return response;
    }
};
