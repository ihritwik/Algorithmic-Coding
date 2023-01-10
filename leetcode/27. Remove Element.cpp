#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort (nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            while(std::find(nums.begin(), nums.end(), val)!=nums.end()){
                nums.erase(std::find(nums.begin(), nums.end(), val));
            }
        }
        return (nums.size());
    }
};