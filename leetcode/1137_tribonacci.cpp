/* The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn. */

#include<iostream>
#include<vector>
// int trib(int n){
//     int dp[3]={0,1,1};
//     for(int i=3;i<=n;i++){
//         dp[i%3]+=dp[(i+1)%3]+dp[(i+2)%3];
//     }
//     return dp[n%3];
// }


// memoization
class Solution{
    public:
        int mk(int n, std::vector<int> &memo){
            if(n<=2) return n==0? 0:1;
            
            if(memo[n] != -1) return memo[n];
            return memo[n]= mk(n-1, memo) + mk(n-2, memo)+ mk(n-3, memo);
        }
        int trib(int n){
            std::vector<int> memo(n+2, -1);
            return mk(n, memo);
        }    
};

int main(){
    int num;
    std::cin>>num;

    Solution s;
    int res= s.trib(num);
    std::cout<<res<<std::endl;
    return 0;
}