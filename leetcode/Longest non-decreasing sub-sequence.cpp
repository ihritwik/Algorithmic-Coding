#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int find_element(vector<int>& sub, int target){
            int l = 0;
            int r = sub.size() -1;
            int mid = l+(r-l)/2;
            
            while (r>l){
                mid = l+(r-l)/2;
                if (sub[mid] == target){
                    r = mid+1;
                    break;
                }
                else if (sub[mid] < target){
                    l = mid+1;
                }
                else
                    r = mid;
            }
            return (r);
        }

    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> sub;
        sub.push_back(nums[0]);
        for (int index = 1; index<nums.size(); index++){
            if (nums[index] >= sub.back()){
                sub.push_back(nums[index]);
            }
            else{
                // Find the element in sub that is equal to or greater than nums[i]
                auto index_to_swap = find_element(sub, nums[index]);
                // Replace this element in sub with nums[i]
                sub[index_to_swap] = nums[index];
            }   
         }
         // Display array
         for (int k = 0; k<sub.size();k++){
             cout<<sub[k]<<" ";
         }
         return (sub.size());    
    }
};