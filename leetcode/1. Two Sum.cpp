#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:           
    vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> data;
    vector<int> response;
    int z;
    for (int i = 0; i < nums.size(); ++i) {
      int z = target - nums[i];
      if (data.find(z) != data.end()) {
        response.push_back(i);
        response.push_back(data[z]);
      } else 
      {
        data[nums[i]] = i;
      }
    }
    return response;
  }

};