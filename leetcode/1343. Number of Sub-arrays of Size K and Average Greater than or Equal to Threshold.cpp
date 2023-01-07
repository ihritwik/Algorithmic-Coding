#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // Approach 2: Sliding window
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int curr_sum=0, avg=0, count=0;
        for (int i =0; i<arr.size(); i++){
            curr_sum+=arr[i];
            if (i>=k-1){
                avg=curr_sum/k;
                if (avg>=threshold) count+=1;
                curr_sum-=arr[i+1-k];
            }
        }
        return count;
    }
};

// Brute force solution
        // int count=0;
        // int ptr1 = 0, ptr2 = 0;
        // for(int r=0; r<=arr.size()-k; r++){
        //     int sum=0, avg=0;
        //     ptr1=r;
        //     ptr2=ptr1+k-1;
        //     for(int i = ptr1; i<=ptr2; i++){
        //         //cout<<arr[i]<<" ";
        //         sum+=arr[i];
        //     }
        //     //cout<<endl;
        //     avg = sum/k;
        //     //cout<<sum<<" "<<avg<<endl;
        //     if(avg>=threshold) 
        //         count+=1;
        // }