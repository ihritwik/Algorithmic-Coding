#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for (int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size();j++){
                if (nums[i]==nums[j]) count+=1;
            }
        }
        return count;
    }
};