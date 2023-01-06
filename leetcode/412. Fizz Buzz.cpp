#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i=0; i<n;i++){
            if (((i+1)%3==0) && ((i+1)%5==0))
                ans[i] = "FizzBuzz";
            else if (((i+1)%5==0)&&((i+1)%3!=0))
                ans[i] = "Buzz";
            else if (((i+1)%3==0) && ((i+1)%5!=0))
                ans[i] = "Fizz";
            else
                ans[i] = to_string(i+1);
        }
        return ans;
    }
};