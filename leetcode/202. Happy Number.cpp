#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int replacenumber(int num){
        int d, sum=0;
        while(num>0){
            d=num%10;
            sum+=(d*d);
            num = num/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow_ptr = n;
        int fast_ptr = replacenumber(n);
        
        while ((fast_ptr!=1)&&(slow_ptr!=fast_ptr)) {
            slow_ptr = replacenumber(slow_ptr);
            fast_ptr = replacenumber(replacenumber(fast_ptr));
        }
        return (fast_ptr==1);
    }
};