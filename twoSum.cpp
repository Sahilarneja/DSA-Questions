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