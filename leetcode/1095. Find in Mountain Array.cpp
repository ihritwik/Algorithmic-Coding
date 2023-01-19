
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
   public:
     int get(int index);
     int length();
 };

class Solution {
public:
    int left_binarySearch(MountainArray &mountainArr,int start,int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target) 
                return mid;
           else if(mountainArr.get(mid)<target) //Moving Forward Ascending Array
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    int right_binarySearch(MountainArray &mountainArr,int start,int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target) //Moving Forward Descending Array
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int start=0,end=len-1;
        int peak_element;
        while(start<end){ // Finding Peak Element
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid+1)>mountainArr.get(mid)){
                start=mid+1;
                peak_element=mid+1;
            }
            else
                end=mid;
        }
        int left = left_binarySearch(mountainArr,0,peak_element,target); // Towards Left of the array
        int right = right_binarySearch(mountainArr,peak_element,len-1, target); // Towards Right of the array
        return left>=0? left:right; //If target is present on the left return it otherwise the index at right
				//If not present we will return -1 as answer
    }
};