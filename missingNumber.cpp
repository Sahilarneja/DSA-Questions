class Solution {
public:

    int sortingMethod(vector<int>&nums){
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==nums[i]){
                continue;
            }else{
                return i;
            }
            
        }
        return nums.size();
    }


    int xorr(vector<int>&nums){
        int ans=0;
// 1) xor of all values in array
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }

        //2) xor of all range items
        for(int i=0;i<=nums.size();i++){
            ans^=i;
        }
        return ans;
    }
    
    int missingNumber(vector<int>& nums) {
        return xorr(nums);
    }
};