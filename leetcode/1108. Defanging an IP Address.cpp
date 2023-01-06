#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string response;
        for (int i=0; i<address.length();i++)
        {
            if(address[i]=='.'){
                response.push_back('[');
                response.push_back('.');
                response.push_back(']');
            }
            else
                response.push_back(address[i]);
        }
        return response;
    }
};