#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_nums1 = 0;
        int ptr_nums2 = 0;
        int ptr;
        vector<int> nums1_cpy = nums1;
        nums1.resize(m+n);

        for(int ptr=0; ptr< (m+n); ptr++){
            if ((ptr_nums2>=n) || ((ptr_nums1<m)&&(nums1_cpy[ptr_nums1]<nums2[ptr_nums2]))){
                nums1[ptr] = nums1_cpy[ptr_nums1++];
            }
            else {
                nums1[ptr] = nums2[ptr_nums2++];
            }
        }    
    }
};