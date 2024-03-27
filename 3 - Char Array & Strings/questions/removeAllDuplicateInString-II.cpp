// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:

    bool areLast_1CharsSame(string& ans, char& newch, int k_1) {
        int it = ans.size() - 1;
        for (int i = 0; i < k_1; i++) {
            if (newch != ans[it]) {
                return false;
            }
            it--;
        }
        return true;
    }

    string removeDuplicates(string s, int k) {
    //     string ans;
    //     for (char newch : s) {
    //         if (ans.size() < k - 1) {
    //             ans.push_back(newch);
    //         }
    //         else {
    //             if (areLast_1CharsSame(ans, newch, k - 1)) {
    //                 for (int j = 0; j < k - 1; j++) {
    //                     ans.pop_back();
    //                 }
    //             }
    //             else {
    //                 ans.push_back(newch);
    //             }
    //         }
    //     }
    //     return ans;
    // }


    //two pointer approach
        int n = s.size();
        int i = 0, j = 0;
        vector<int> count(n);

        while (j < n) {
            s[i] = s[j];
            count[i] = 1;

            if (i > 0 && s[i] == s[i - 1]) {
                count[i] += count[i - 1];
            }

            if (count[i] == k) {
                i -= k;
            }
            ++i;
            ++j;
        }
        return s.substr(0, i);
    }
};