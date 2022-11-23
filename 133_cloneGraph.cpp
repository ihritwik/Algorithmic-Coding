#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs_visit(Node* curr, unordered_map<Node*, Node*> & mp) {
        vector<Node*> neighbor;
        Node* response = new Node(curr->val);
        mp[curr] = response;
        for (auto it : curr->neighbors){
            if (mp.find(it) != mp.end()){
                neighbor.push_back(mp[it]);
            }
            else{
                neighbor.push_back(dfs_visit(it,mp));
            }
        }
        response->neighbors = neighbor;
        return response;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> map1;
        if (node == NULL){
            return NULL;
        }
        if (node->neighbors.size() == 0){
            Node* response = new Node(node->val);
            return response;
        }
        return dfs_visit(node, map1);
    }
};
