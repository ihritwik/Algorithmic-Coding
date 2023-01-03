#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> data;
        vector<int> count;
        bool response = true;
        // initialize count as zero
        for (int i = 0; i<arr.size()-1; i++){
            data[arr[i]] = 0;
        }
        // update data
        for(auto it = arr.begin(); it!=arr.end(); ++it){
            data[*it]+=1;
        }

        // update count 
        for(auto it = data.begin(); it!=data.end(); ++it){
            count.push_back(it->second);
        }
        sort(count.begin(),count.end());
        // check for repetition
        for (int i = 0; i<count.size()-1; i++){
            if (count[i]==count[i+1]){ 
                response = false;
                break;
                }
            else { continue;}
        }
        return response;
    }
};
