#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> data (nums.size());
        int recent_repeat_index;
        for (int i = 0; i<nums.size(); i++){
            if (data.find(nums[i])==data.end()){
                data[nums[i]] = i;
            }
            else{
                if((abs(i-data.find(nums[i])->second))<=k){
                    cout<<(abs(i-(data.find(nums[i])->second)));
                    return true;
                }
                else {
                    //remove the element from map and insert the recent element
                    data.erase(data.find(nums[i]));
                    //update map
                    data[nums[i]]=i;
                }
            }
        }
        return false;
    }
};