#include <bits/stdc++.h>
#include <array>
#include <algorithm> 
using namespace std;

class Solution {
    public:
        int find_first_index(vector<int>& arr, int target, int mid){
            while(mid!=0){
                if (arr[mid-1] == arr[mid]){
                    cout<<"repetitive index = "<<mid<<endl;
                    mid--;
                }
                else
                    break;
            }
            return mid; 
        }

        int find_last_index(vector<int>& arr, int target, int mid){
            while(mid!=0){
                if (arr[mid+1] == arr[mid]){
                    mid++;
                }
                else 
                    break;
            }
            return mid;
        }

        int binary_search(vector<int>& arr, int first, int last, int target)
        {
            //int *result = &res;
            int mid = (first +last)/2;   
            
            //cout<<"first = "<<first<<" last = " << last <<" Mid = "<<mid<<endl;
            

            if (first>last)
            {   
                cout<<"Number not found due to first > last "<< endl;
                return -1;
                //*result = -1;
                //cout<< "Response = "<<*result<<endl;
            }

            else if ((first == last) && (arr[mid] != target)){
                //cout<<"Number not found "<< endl;
                return -1;
                //*result = -1;
                //cout<< "Response = "<<*result<<endl;
            }
                        
            else if(arr[mid] == target)
            {
                //cout<< "Number found at index "<< mid<<endl;
                
                // find first index of repetitive numbers
                return (find_first_index(arr, target, mid));
                
                // find last index of repetitive numbers. 
                // return (find_last_index(arr, target, mid));

                // return mid;
                //*result = mid;
                //cout<< "Response = "<<*result<<endl;             
            }

            else if (arr[mid]<target)
            {
                //cout << "Got mid more: Looking in upper half. mid = " << mid << endl;
                return binary_search(arr, mid + 1, last, target);
           
            }

            else if (arr[mid]>target)
            {
                //cout << "Got mid less: Looking in lower half." << mid << endl;
                return binary_search(arr, first, mid -1, target);  

            }
            return 0;
        }
    
        int search(vector<int>& nums, int target) 
        {
            int first = 0;
            int last = (nums.size())-1;
            //cout<<"Last = " <<last<<endl;
            
            // for(auto it = nums.begin(); it != nums.end(); it++){
            //     cout << *it << " ";
            // }
            //cout << "\ntarget: " << target << endl;
            //cout << "\nSize: " << last+1 << endl;
            int mid = (first +last)/2;
            int result = binary_search(nums, first, last, target);    
            //cout<< "Answer of function = "<<result<<endl;
            return result;   
        }
};

int main() {
    vector<int> nums {1, 12, 13, 13, 14, 16, 16, 16, 18, 20, 22, 22, 23, 34, 34, 34, 34, 34, 37, 37, 37, 37};
    int target = 22;
    Solution obj;
    cout<<"start"<<endl;
    int answer = obj.search(nums, target);
    cout<< "Index : "<<answer<<endl;
    
}	
