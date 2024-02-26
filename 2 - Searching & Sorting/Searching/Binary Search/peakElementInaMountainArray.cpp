// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(arr[mid]<arr[mid+1]){
                //a wali line m hu
                //peak right m exist krti h
                s=mid+1;
            }else{
                //ya to main b line pr hu
                //ya to peak element pr hu
                e=mid;
            }
            //mid update
            mid=s+(e-s)/2;
        }
        return s;
    }
};