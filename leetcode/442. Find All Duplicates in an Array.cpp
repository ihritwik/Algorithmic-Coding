#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> response (nums.size()+1,0);
        vector<int> answer;
        for (auto &digit:nums ){
            response[digit] += 1;
            //cout<<digit<<" "<<response[digit]<<endl;
            if ((response[digit])==2){
                answer.push_back(digit);
                //cout<<"pushed in answer "<<digit<<endl;
            }
        }
        return answer;
    }
};