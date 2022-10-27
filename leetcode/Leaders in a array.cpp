#include <bits/stdc++.h>
using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    void checkLeader(int a[],int n,vector<int> &response,int max){
        if(n==0)
            return;
        if(a[n-1] >= max){
            response.push_back(a[n-1]);
            max = a[n-1];
        }
        checkLeader(a,n-1,response,max);
        return;
    }
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> response;
        checkLeader(a,n,response,INT_MIN);
        reverse(response.begin(),response.end());
        return response;
    }
};

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        cout << endl;
   }
}
