#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> response(2);
        unordered_set<int> visited_nums1, visited_nums2;
        
        for (auto& i : nums1)
            visited_nums1.insert(i);
        for (auto& j : nums2)
            visited_nums2.insert(j);  
        
        for (auto& i : nums1){
            if ((visited_nums2.count(i)==0) && (find(response[0].begin(), response[0].end(),i)== response[0].end()))
                response[0].push_back(i);
        }
        for (auto& j : visited_nums2)
        {   
            if ((visited_nums1.count(j)==0) && (find(response[1].begin(), response[1].end(),j)== response[1].end()))
                response[1].push_back(j);
        }
        return response;
    }
};