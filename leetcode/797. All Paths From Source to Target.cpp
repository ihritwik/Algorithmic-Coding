#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int> path = {0};
        vector<vector<int>> response={};
        dfs(0, path, graph, target, response);
        return response;
    }
    function<void(int, vector<int>&, vector<vector<int>>&, int, vector<vector<int>>&)> dfs = [&] (int node, vector<int>& path, vector<vector<int>>& graph, int target, vector<vector<int>>& response){
        if (node==target){
            response.push_back(path);
            return;
        }
        for (auto neighbor: graph[node]){
            path.push_back(neighbor);
            dfs(neighbor, path, graph, target, response);
            path.pop_back();
        }
    };
};
Console
