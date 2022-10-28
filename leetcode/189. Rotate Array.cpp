#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // Aproach 1: Time Complexity O(n)
    
    void rotate(vector<int>& nums, int k) {
        vector<int> nums_cpy = nums;
        int start = 0;
        k %= nums.size();
        int offset;
        int cpy_ptr = nums.size()-k;
        int temp, previous;
        for (int i = 0; i < k; i++) 
        {
            nums[i] = nums[cpy_ptr];
            cpy_ptr++;
            offset = i;
        }    
        for (int j = offset+1; j < nums.size(); j++) 
        {
            nums[j] = nums_cpy[start++];
            
        }
    }    
};

// Approach 2 : Space Complexity : O(1)

// void rotate(vector<int>& nums, int k) {
//         k %= nums.size();
//         //cout<<"k= "<<k<<endl;
//         int temp, previous;
//         for (int i = 0; i < k; i++) 
//         {
//             //cout<<"i= "<<i<<endl;
//             previous = nums[nums.size() - 1];
//             //cout<<"previous= "<<previous<<endl;
//             for (int j = 0; j < nums.size(); j++) 
//             {
//             temp = nums[j];
//             nums[j] = previous;
//             previous = temp;
//         }
//         //Display after each place rotation
//         // for(int z=0; z<nums.size();z++){
//         //     cout<<nums[z]<<"  ";
//         // }
//         // cout<<endl;
//     }    
// }
