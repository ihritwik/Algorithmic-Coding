#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Your code here
        long count_check = 0;
        long max_sum = INT_MIN;
        
        for (int i = 0;i<nums.size();i++){
            count_check += nums[i];
            
            if (max_sum<count_check){
                max_sum=count_check;
            }
            
            if (count_check<0){
                count_check = 0;
                }
        }
        return max_sum;
    }
};
