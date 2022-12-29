#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        //Variable assignment
        int rem = 0; 
        long long rev = 0;
        int quotient;
        int digit = 0;
        long long n = x;

        // Base case
        if ((x>=INT_MAX)||(x<=INT_MIN)){
            return 0;
        }
        // Check for negative and convert to positive for ease of calculation
        if (n<0){
            n=(-1)*x;
        }   
        
        while(n>0){
            rem = n%10;
            rev = rev*10+rem;
            n = n/10;
            digit++;
        }

        // Check reversed number is positive or negative and return result accordingly
        if (rev>=INT_MAX){
            return 0;
        }
        else{
            if (x<0){
                rev = -1*rev;
                return (rev);
            }
            else{
                return (rev);
            }
        }
    }
};