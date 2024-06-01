// https://leetcode.com/problems/maximum-subarray/submissions/1273839712/
class Solution {
public:

    int maxSubArraySol(vector<int> &v, int start, int end){

        if(start == end){
            return v[start];
        }

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;
        int leftBorderSum = 0;
        int rightBorderSum = 0;

        int mid = start+(end - start)/2;

        int leftSum = maxSubArraySol(v, start, mid);
        int rightSum = maxSubArraySol(v, mid+1, end);

        //left border sum
        for(int i = mid; i>=start; i--){
            leftBorderSum += v[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        //right border sum
        for(int i = mid+1 ; i<=end; i++){
            rightBorderSum += v[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(crossBorderSum, max(leftSum, rightSum));


    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArraySol(nums, 0, nums.size() - 1);
    }
};