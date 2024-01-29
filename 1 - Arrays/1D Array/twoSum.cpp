#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool twoSum(int arr[], int n, int x) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == x) {
                    return true;
                }
            }
        }
        return false;
    }

    bool twoSum2Pointer(int arr[], int n, int x) {
        int l = 0;
        int h = n - 1;
        while (l < h) {
            int cSum = arr[l] + arr[h];
            if (cSum == x) {
                return true;
            } else if (cSum > x) {
                h--;
            } else {
                l++;
            }
        }
        return false;
    }

    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        sort(arr, arr + n);
        return twoSum2Pointer(arr, n, x);
    }
};

int main() {
    Solution solution;
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    if (solution.hasArrayTwoCandidates(arr, n, target)) {
        cout << "Array has two elements that sum up to the target." << endl;
    } else {
        cout << "Array does not have two elements that sum up to the target." << endl;
    }

    return 0;
};

// Solution2:
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return{};
//     }
// };