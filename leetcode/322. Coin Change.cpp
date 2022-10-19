#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        // Dynamic Programming (Bottom up approach). Time complexity : O(S*n), Space Complexity O(S)
        
        // Initialize DP table and fill all elements in it with max value (amount +1)
        int dp[amount+1];
        std::fill_n (dp, amount+1, amount+1);
        dp[0] = 0;
        
        for (int coin=1; coin<=coins.size(); coin++)
        {
            for (int i = coins[coin-1]; i<=amount; i++)
            {
                dp[i] = std::min(dp[i], dp[i-coins[coin-1]] + 1);
            }   
        }

        if (dp[amount] >= amount+1)
        {
            return -1;
        }    
        else{
            return (dp[amount]);
        }
    }
};