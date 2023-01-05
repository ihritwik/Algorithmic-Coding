#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    // Recursion Approach : Time complexity (2^n)
    
    // int fib(int n) {
    //     if (n==0)return 0;
    //     if (n==1) return 1;
    //     else return fib(n-1)+fib(n-2);
    // }

    // Dynamic Programming : Bottom up spproach
    int fib(int n) {
        if ((n<=1))return n;
        vector<int> response (n+1,0);
        response[1]=1;
        for (int i =2; i<=n; i++){
            response[i] = response[i-1]+response[i-2];
        }   
        return response[n];
    }
};
