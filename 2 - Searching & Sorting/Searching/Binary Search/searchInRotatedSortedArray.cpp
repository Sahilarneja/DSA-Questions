// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1180287591/
class Solution {
public:
    int findPivotIndex(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1; 
        while(s <= e) { 
            int mid = s + (e - s) / 2; 
            if(s == e) {
                return s;
            } else if(mid > 0 && nums[mid] < nums[mid - 1]) { 
                return mid - 1;
            } else if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) { 
                return mid;
            } else if(nums[s] > nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1; 
            }
        }
        return -1;
    }

    int binarySearch(vector<int>& arr, int s, int e, int target){
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid] == target){
                return mid;
            } else if(target > arr[mid]){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target){
        int pivotIndex = findPivotIndex(nums);
        int ans = -1;

        // Search in the first part of the array
        if(target >= nums[0] && target <= nums[pivotIndex]){
            ans = binarySearch(nums, 0, pivotIndex, target);
        } else {
            // Search in the second part of the array
            ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }
        
        return ans;
    }
};
