// https://leetcode.com/problems/longest-valid-parentheses/description/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxi = 0;

        // Left to right scan
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (right > left) {
                left = right = 0;
            } else if (left == right) {
                maxi = max(maxi, left * 2);
            }
        }

        left = 0;
        right = 0;

        // Right to left scan
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left > right) {
                left = right = 0;
            } else if (left == right) {
                maxi = max(maxi, left * 2);
            }
        }

        return maxi;
    }
};