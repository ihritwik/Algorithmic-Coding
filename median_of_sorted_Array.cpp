#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double length_of_both_array = nums1.size() + nums2.size();
        double mid = length_of_both_array/2;
        double j = 2;
        vector<int> mergedArr = mergedArray(nums1, nums2, mid);
        if (fmod(mid,j) != 0){
            cout<< "Median = "<<mergedArr[mid];
            return (double(mergedArr[mid]));
        }
        else{
            cout<< "Median = "<<double((mergedArr[mid]+mergedArr[mid+1])/2);
            return (double((mergedArr[mid]+mergedArr[mid+1])/2));
        }
    }
    vector<int> mergedArray(vector<int>& nums1, vector<int>& nums2, double mid){
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        vector<int> res;
        if (nums1.size() == 0) return nums2;
        if (nums2.size() == 0) return nums1;
        while ((ptr1 < nums1.size()) && (ptr2 < nums2.size()) && (ptr3 <= mid))
        {
                if (nums1[ptr1] < nums2[ptr2])
                    res[ptr3++] = nums1[ptr1++];
                else
                    res[ptr3++] = nums2[ptr2++];
        }
        return res;
    }
};
int main(){
    Solution ob;
    vector<int> Arr1 = {1,2};
    vector<int> Arr2 = {3};
    ob.findMedianSortedArrays(Arr1, Arr2);
    return 0;
}