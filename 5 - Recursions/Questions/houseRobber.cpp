https://leetcode.com/problems/house-robber/submissions/1226722570/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int size, int index) {
        // Base case
        if (index >= size) {
            return 0;
        }

        // Option 1: ith pr chori krli
        int option1 = nums[index] + solve(nums, size, index + 2);

        // Option 2: ith pr chori nhi kri 
        int option2 = solve(nums, size, index + 1);

        
        return max(option1, option2);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        return solve(nums, size, index); 
    }
};
