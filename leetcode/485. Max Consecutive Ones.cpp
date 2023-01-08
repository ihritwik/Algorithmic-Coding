#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k=0;
        int left =0, right;
        for (right=0; right<nums.size(); right++){
            if (nums[right]==0){
                k--;
            }
            if (k<0){
                if (nums[left]==0)
                    k++;
                left++;
            }
        }
        return right-left;
    }
};