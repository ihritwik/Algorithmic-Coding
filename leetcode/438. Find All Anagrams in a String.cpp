#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> response;
        if (p.length()>s.length()) return response;
        
        vector<int> count_p(26,0);
        vector<int> count_s(26,0);

        for(int i = 0; i<p.length();i++){
            count_p[p[i]-'a']+=1;
            count_s[s[i]-'a']+=1;
        }
        if (count_p==count_s) response.push_back(0);
        for (int i = p.length(); i<s.length();i++){
            count_s[s[i-p.length()]-'a']-=1;
            count_s[s[i]-'a']+=1;
            if (count_p==count_s) response.push_back(i-p.length()+1);
        }
        return response;
    }
};