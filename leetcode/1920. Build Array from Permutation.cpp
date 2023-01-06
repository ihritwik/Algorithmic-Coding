#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> answer (nums.size());
        for(int i = 0; i<nums.size(); i++){
            answer[i] = nums[nums[i]];
        }
        return answer;
    }
};