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
        for (int i = 0; i < s.length(); i++) {
            //ODD
            int j=i;
            int oddKaAns = expand(s, i, j);

            //Even
            j=i+1;
            int evenKaAns = expand(s, i, j );
            totalCount += oddKaAns + evenKaAns;
        }
        return totalCount;
    }
};

