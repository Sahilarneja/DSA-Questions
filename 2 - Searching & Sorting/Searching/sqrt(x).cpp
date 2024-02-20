// https://leetcode.com/problems/sqrtx/submissions/1181097079/
class Solution {
public:
    int mySqrt(int x) {
        int s = 0; // Start of the search range
        int e = x; // End of the search range
        int ans = -1; // Variable to store the result

        // Binary search loop
        while (s <= e) {
            long long int mid = s + (e - s) / 2; // Calculate the middle value

            // Check if the square of mid is equal to x
            if (mid * mid == x) {
                // If yes, mid is the square root of x
                return mid;
            } else if (mid * mid < x) {
                // If the square of mid is less than x, update ans and move to the right half
                ans = mid;
                s = mid + 1;
            } else {
                // If the square of mid is greater than x, move to the left half
                e = mid - 1;
            }
        }

        // Return the last stored answer
        return ans;
    }
};
