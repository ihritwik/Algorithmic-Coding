#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        unordered_map<char, char> data;
        int s_length = s.length();
        data['('] = ')';
        data['{'] = '}';
        data['['] = ']';
        for (auto& ch:s){
            if ((store.empty())||((ch=='('||ch=='{'||ch=='[')&&(store.top()=='('||store.top()=='{'||store.top()=='[' ))){    
                store.push(ch);
            }
            if (ch=='}'||ch==')'||ch==']'){
                if (data[store.top()]==ch){
                    store.pop();                 
                }
                else
                    return false;
            }        
        }
        if (store.empty()){return true;}
        else return false;
    }
};