class Solution {
public:
        //TC: O(N^2)
    // double bruteForce(vector<int>& nums, int k){
    //     int max=INT_MIN;
    //     int i=0, j=k-1;
    //     while(j<nums.size()){
    //         int sum=0;
    //         for(int y=i;y<=j;++y){
    //             sum+=nums[y];
    //         }
    //         maxSum=max(maxSum,sum);
    //         ++j, ++i;
    //     }
    //     double maxAvg= maxSum / (double)k;
    //     return maxAvg;
    // }
    
    double slidingWindow(vector<int>& nums, int k){
        int i = 0, j = k - 1;
        int sum = 0;

        for (int y = i; y <= j; ++y) {
            sum += nums[y];
        }

        int maxSum = sum;  // Declare maxSum before using it
        j++;

        while (j < nums.size()) {
            sum -= nums[i++];
            sum += nums[j++];
            maxSum = max(maxSum, sum);  // Update maxSum
        }

        double maxAvg = maxSum / static_cast<double>(k);
        return maxAvg;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        return slidingWindow(nums, k);
    }
};
