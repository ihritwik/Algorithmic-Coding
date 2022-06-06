#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) 
        {
            vector<int> start_time;
            vector<int> end_time;
            int sz = intervals.size();
            int start_index = 0;
            int end_index = 1;
            // Separate the start time and end time
            for (int i=0; i<sz; i++){
                start_time.push_back(intervals[i][start_index]);
                end_time.push_back(intervals[i][end_index]);
            }
            // Sort both vectors individually
            sort(start_time.begin(), start_time.end());
            sort(end_time.begin(), end_time.end());

            int start_ptr = 0;
            int end_ptr = 0;
            int rooms = 0;
            while (start_ptr < intervals.size())
            {    
                if (start_time[start_ptr] >= end_time[end_ptr]) //meeting ended so room vacated
                {
                    rooms--;
                    end_ptr++;
                }
                rooms++; // meeting not ended so new room assigned
                start_ptr++;
            }
            return rooms;
        }
};
int main(int argc, char const *argv[])
{
    Solution ob;
    //vector<vector<int>> input = {{0,30},{5,10},{15,20}};
    vector<vector<int>> input = {{7,10},{2,4}};
    int result = ob.minMeetingRooms (input);
    cout << "Minimum Rooms required = " << result<<" ";
    return 0;
}