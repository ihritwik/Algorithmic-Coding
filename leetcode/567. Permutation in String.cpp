#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length()>s2.length()) return false;
        vector<int> window(26, 0);
        vector<int> s1_count(26,0);
        for(int i=0; i<s1.length(); i++){
            window[s2[i]-'a']+=1;
            s1_count[s1[i]-'a']+=1;    
        }
        if (window == s1_count) 
            return true;
        for(int i = s1.length(); i<s2.length(); i++){
            window[s2[i-s1.length()]-'a']-=1;
            window[s2[i]-'a']+=1;
            if (window==s1_count) return true;
        }
        return false;
    }
};