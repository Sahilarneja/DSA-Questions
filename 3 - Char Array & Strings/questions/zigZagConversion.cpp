// https://leetcode.com/problems/zigzag-conversion/submissions/1213247689/
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<std::string> zigzag(numRows);

        int i = 0, row = 0;
        bool direction = true;

        while (i < s.size()) {
            zigzag[row].push_back(s[i++]);

            if (direction) {
                if (row == numRows - 1)
                    direction = false;
            } else {
                if (row == 0)
                    direction = true;
            }

            row += (direction ? 1 : -1);
        }

        std::string ans = "";
        for (const auto& str : zigzag) {
            ans += str;
        }
        return ans;
    }
};