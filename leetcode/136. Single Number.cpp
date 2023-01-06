#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        unordered_map<int, int> data;
        for (int i=0; i<nums.size(); i++){
            data[nums[i]]+=1;
        }
        for (auto &it : data){
            if (it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};