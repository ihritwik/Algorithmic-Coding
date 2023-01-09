// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	// Your code here
    	int i = 0, j = n-1;
    	vector<long long> V1;
    	if (n==0) return;
    	if (n==1) return;
    	for (int i=0; i<n/2; i++)
    	{
    	    V1.push_back((arr[j]*1000000)+arr[i]);
    	    j--;
    	    
    	}
    	if (n%2 != 0)
    	    V1.push_back(arr[n/2]);
    	
    	for (i = 0; i<n/2;i++)
    	{
    	       arr[2*i] = V1[i]/1000000;
    	       arr[(2*i)+1] = V1[i]%1000000;   
    	}
    	if (n%2 != 0)
    	       arr[n-1] = V1[n/2] ;
    	 
    }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends