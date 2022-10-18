#include <bits/stdc++.h>
#include <array>
#include <algorithm> 
using namespace std;

class Solution {
    public:
        void selection_sort(int *A, int sz)
        {
            int swap;
            for (int i=0; i<sz-1; i++){
                // Find the minimum element in the array and its index
                int loc_min = *min_element(A+i,A+sz);
                int index = find(A, A+sz, loc_min)-A;
                //interchange local_min with number in A[i];
                swap = A[i];
                A[i] = loc_min;
                A[index] = swap;
            }
            // Dsiplay sorted elements
            for (int k=0; k<sz; k++)
            {
                cout<<A[k]<<" ";
            }
        }
        
};

int main() {
    int arr[] = {10, 1, 15, 32, 3, 8};
    int sz_real = sizeof(arr)/sizeof(int);
    Solution obj;
    obj.selection_sort(arr, sz_real);
}	
