#include <vector>

class Solution {
public:
    int bruteForce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int lSum = 0;
            int rSum = 0;

            // for lSum
            for (int j = 0; j < i; j++) {
                lSum += nums[j];
            }

            // for rSum
            for (int j = i + 1; j < nums.size(); j++) {
                rSum += nums[j];
            }

            if (lSum == rSum) {
                return i;
            }
        }

        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return bruteForce(nums);
    }
};