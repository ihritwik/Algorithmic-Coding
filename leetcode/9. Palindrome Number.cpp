#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int rem, div;
        
        if ((x<0)  || (x%10 == 0 && x!=0)) return false;      
        int reversed_num=0;
        int remainder = 0;
        while (x>reversed_num){
            remainder = x%10;
            reversed_num = reversed_num*10 + remainder;
            x = x/10;
        }
        
        return ((reversed_num==x)|| (x==reversed_num/10));
    }
};