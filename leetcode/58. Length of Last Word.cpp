#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int it = s.size()-1;
        while (s[it]==' '){
            cout<<"entered"<<endl;
            it--;
        }
        cout<<it;
        for (it;it>=0; it--){
            if(s[it]!=' ') {
                count=count+1;
                cout<<s[it]<<" "<<count<<endl;}
            else break;
        }
        return count;
    }
};