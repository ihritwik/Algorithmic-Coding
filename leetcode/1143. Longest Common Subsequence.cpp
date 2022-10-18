#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
     // Approach 2: Dynamic Programming
       
       // Get length of input strings
       int m = text1.length(); 
       int n = text2.length();

       // Define dp table
       int dp[m+1][n+1];
       
       // Fill first row in dp table as zeroes
       for (int i = 0; i<m+1; i++)
       {
              dp[i][0] = 0;
       }
       // Fill first column in dp table as zeroes
       for (int j = 0; j<n+1; j++)
       {
              dp[0][j] = 0;
       }
        
       // Loop in the dp table to fill out the values
       for (int i = 1; i<m+1; i++)
       {
           for (int j = 1; j<n+1; j++)
           {
               if (text1[i-1] == text2[j-1])
               {
                   dp[i][j] = (1+dp[i-1][j-1]);
               }
               else
               {
                   dp[i][j] = (max(dp[i-1][j], dp[i][j-1]));
               }   
            }
        }
        return dp[m][n]; 
    }
};

//         // Approach 1: Recursion. (Time limit will exceed)

//         int m = text1.length(); 
//         int n = text2.length();
        
//         if (m==0 || n==0)
//         {
//            return 0;
//         }
        
//         if (text1[m-1] == text2[n-1])
//         {
//             return (1+longestCommonSubsequence(text1.substr(0,m-1), text2.substr(0,n-1)));
//         }
        
//         if (text1[m-1] != text2[n-1])
//         {
//             return (max(longestCommonSubsequence(text1.substr(0, m-1), text2.substr(0,n)),longestCommonSubsequence(text1.substr(0,m), text2.substr(0,n-1))));
                                                   
//         }
//         return -1;