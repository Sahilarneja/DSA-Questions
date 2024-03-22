// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string ans;

        // Edge case: empty input vector
        if (strs.empty()) {
            return ans;
        }

        int i = 0;
        while (true) {
            char curr_ch = 0; // Initialize current character to 0
            
            // Iterate through each string in the vector
            for (auto& str : strs) {
                // If current index is out of bound
                if (i >= str.size()) {
                    curr_ch = 0;
                    break;
                }

                // If it's the first character in the loop, set it as current character
                if (curr_ch == 0) {
                    curr_ch = str[i];
                } 
                // If the current character doesn't match, break the loop
                else if (str[i] != curr_ch) {
                    curr_ch = 0;
                    break;
                }
            }

            // If current character is 0, break the while loop
            if (curr_ch == 0) {
                break;
            }
            
            // Append current character to the answer
            ans.push_back(curr_ch);
            i++; // Move to the next character
        }

        return ans;
    }
};
