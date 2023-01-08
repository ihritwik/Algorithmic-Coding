#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int response = 0;
        int left = 0, right = 0;
        vector<int> window(26,0);
        while(right<s.size()){
            window[(s[right]-'a')]+=1;
            //Remove duplicate values
            while (window[s[right] - 'a'] > 1) {
                window[s[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == k) {
                response++;
                window[s[left] - 'a']--;
                left++;
            }
            right++;    
        }
        return response;
    }
};