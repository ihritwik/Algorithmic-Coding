#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int count = 0;
        if ((s.length()==0)||(s.length()==1)||(s.length()==2)) return 0;
        for (int i=0; i<s.length()-2; i++){
            if ((s[i]!=s[i+1])&&(s[i+1]!=s[i+2])&&(s[i]!=s[i+2])){
                count++;
                //cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
            }
        }
        return count;
    }
};