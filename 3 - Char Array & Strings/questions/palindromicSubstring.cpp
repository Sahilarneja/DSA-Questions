// https://leetcode.com/problems/palindromic-substrings/submissions/1207912451/
class Solution {
public:
    int expand(string s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        for (int center = 0; center < s.length(); center++) {
            //ODD
            int oddKaAns = expand(s, center, center);

            //Even
            int evenKaAns = expand(s, center, center + 1);
            totalCount += oddKaAns + evenKaAns;
        }
        return totalCount;
    }
};
