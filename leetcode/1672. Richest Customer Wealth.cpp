#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int banks = accounts[0].size();
        vector<int> wealth (accounts.size());
        for (int i=0;i<accounts.size();i++){
            for (int j=0; j<banks; j++ ){
                wealth[i]+=accounts[i][j];    
            }
        }
        return *max_element(wealth.begin(),wealth.end());
    }
};