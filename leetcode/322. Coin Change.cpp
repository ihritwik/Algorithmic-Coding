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

    // int helper_recursion(vector<int>& coins, vector<int>& change, int amount, int sz_real)
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
    //         if (freq>0){
    //             for (int index=1; index<=freq; index++)
    //             {
    //                change.push_back(coins[0]);
    //             }   
    //         }
    //         amount = amount%coins[sz_real-1]; 
    //         return (freq + helper_recursion(coins, change, amount, sz_real-1));   
    //     }
    //     return 0;
	// }

    // vector<int> coinChange(vector<int>& coins, int amount) 
    // {   
    //     vector<int> change;
    //     int number_of_coins = helper_recursion(coins, change, amount, coins.size());
    //     return change;
    // }


    // Approach 3: Non-recursive algorithm

    // int helper_recursion(vector<int>& coins, vector<int>& change, int amount, int sz_real)
	// {
    //     int minimum_coins=0;
    //     while(amount!=0){
    //         for(int index=0;index<coins.size();index++){
    //             if (amount>coins[index])
    //             {
    //                 amount=amount-coins[index];
    //                 minimum_coins++;
    //             }
    //         }
    //     }
    //     return minimum_coins;
    // }

    // int coinChange(vector<int>& coins, int amount) 
    // {   
    //     vector<int> change;
    //     return helper_recursion(coins, change, amount, coins.size());
    // }

