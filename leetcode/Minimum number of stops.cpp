#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:
        // Time Complexity is O(n)
        vector<int> minStops(vector<int> distances, int gas_fill)
        {
            vector<int> stops;
            vector<int> diff_arr;
            int min_stops = 0; 
            // Loop running n times, so running time is O(n)
            for(int i=distances.size()-1; i>0; i++)
            {
                // Calculate values of diff_arr
                diff_arr[i] = distances[i] - distances[i-1];
            }
            diff_arr[0] = distances[0];
            int remaining_dist = gas_fill - diff_arr[0];
            
            // Time Complexity of the loop below is of the order O(n) 
            for (int k=1; k<diff_arr.size(); k++){
                if (diff_arr[k] > remaining_dist){
                    remaining_dist += gas_fill;
                    min_stops++;
                    stops.push_back(k);
                }
                else{
                    remaining_dist -= diff_arr[k];
                }
            }
            cout<<"Minimum number of stops = "<< diff_arr[k];
            return (stops);
        }
};
