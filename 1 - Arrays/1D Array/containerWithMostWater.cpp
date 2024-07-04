// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;

        while(left<right){
            int length = min(height[left], height[right]);
            int width = right - left;
            int area = length * width;
            maxArea = max(area, maxArea);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};