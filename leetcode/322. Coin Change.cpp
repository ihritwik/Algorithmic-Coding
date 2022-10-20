#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
//  Approach 2: Dynamic Programming (Bottom up approach). Time complexity : O(S*n), Space Complexity O(S)
    int coinChange(vector<int>& coins, int amount) 
    {   
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

// Approach 1: Recursive Greedy approach

    // int helper_recursion(vector<int>& coins, int amount, int sz_real)
	// {
	// 	//sort(coins.begin(), coins.end());
    //     //base case
    //     if (coins.size()==0){
    //         return 0;
    //     }
        
    //     else if (coins.size()==1) {
    //         if (amount == coins[0]){
    //             return 1;
    //         }
    //         else
    //             return -1; 
    //     }
    //     else if (amount>=coins[0]){
    //         int freq = amount/coins[sz_real-1]; 
    //         //min_coins += freq;
    //         amount = amount%coins[sz_real-1]; 
    //         return (freq + helper_recursion(coins, amount, sz_real-1));   
    //     }
    //     return 0;
	// }

    // int coinChange(vector<int>& coins, int amount) 
    // {
    //     return (helper_recursion(coins, amount, coins.size()));
    // }