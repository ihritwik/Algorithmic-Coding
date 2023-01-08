#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //if (k==1) return *max_element(nums.begin(), nums.end());
        double running_sum=0, max_sum=0;
        for (int i= 0; i<k; i++){
            running_sum +=nums[i];
        }
        max_sum=running_sum;
        for (int i = k; i<nums.size(); i++){
            running_sum = running_sum-nums[i-k]+nums[i];
            max_sum = max(max_sum, running_sum);
        }
        return max_sum/k;
    }
};