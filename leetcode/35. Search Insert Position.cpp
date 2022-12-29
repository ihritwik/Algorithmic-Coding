#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x)
    {
        int position;
        if (r >= l) {
            int mid = l + (r - l) / 2;
            // If the element is present at the middle itself
            if (arr[mid] == x)
                return mid;
            // If element is smaller than mid, return
            if (arr[mid] < x)
                return binarySearch(arr, mid + 1, r, x);           
            // We reach here when element is not present in array
            else
                return binarySearch(arr, l, mid-1, x);
        }
        // We reach here when number is not found in the array, i.e., r < l
        return (l);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        vector<int> copy_nums = nums;
        int l = 0;
        int r = nums.size()-1;
        int ans = binarySearch(copy_nums, l, r, target);
        return (ans);
    }
};