#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int find_element(vector<int>& sub, int target)
    {
        int l = 0;
        int r = sub.size() -1;
        int mid = l+(r-l)/2;
        while (r>l)
        {
            mid = l+(r-l)/2;
            if (sub[mid] == target)
            {
                 r = mid;
            }
            else if (sub[mid] < target)
            {
                l = mid+1;
            }
            else
                
                r = mid;
            }
        return (r);
    }
        

    
    int lengthOfLIS(vector<int>& nums) 
    {
        // Approach 2: Time Complexity = O(n*lg n)   
        // initialize sub array that contains the first element of nums
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int index = 1; index<nums.size(); index++)
        {
            if (nums[index] > sub.back())
            {
                sub.push_back(nums[index]);
            }
            else
            {
                // Find the element in sub that is equal to or greater than nums[i]
                auto index_to_swap = find_element(sub, nums[index]);
                // Replace this element in sub with nums[i]
                sub[index_to_swap] = nums[index];
                
            }   
         }
         return (sub.size());    
    }
};

// Approach 1: Time Complexity = O(n^2)

//         // declare array
//         int dp[nums.size()];
//         // initialize dp array
//         for (int index = 0; index < nums.size(); index++) {
//             dp[index] = 1;
//         }
        
//         for (int i = 1; i<nums.size(); i++)
//         {
//             for (int k = 0; k<i; k++)
//             {
//                 if (nums[k] < nums[i])
//                 {
//                     dp[i] = max(dp[i], dp[k]+1);
//                 }
//             }
//          }
//          return (*max_element(dp, dp+nums.size()));
        
 